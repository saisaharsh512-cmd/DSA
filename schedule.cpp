#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void input(int n,vector<pair<int,int>> &arr){
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr[i]={a,b};
    }
}

vector<pair<int,int>> output(vector<pair<int,int>> &arr,int n)
{
    for(int i=0;i<n-1;i++){
        if(arr[i+1].first<=arr[i].second)  //overlapping
        {
            arr[i].second=arr[i+1].second;
            for(int j=i+1;j<n;j++){
                arr[j]=arr[j+1];
            }
            i--;
            n--;
        }
    }
    return arr;
}

void print(vector<pair<int,int>> &arr,int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i].first<<" "<<arr[i].second<<",";
    }
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    input(n,v);
    output(v,n);
    print(v,n);
    return 0;
}