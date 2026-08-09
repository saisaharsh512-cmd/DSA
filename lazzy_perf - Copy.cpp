#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void sort(vector<int> &vol,int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(vol[j]<vol[j+1]){
                int temp=vol[j];
                vol[j]=vol[j+1];
                vol[j+1]=temp;
            }
        }   
    }
}

pair<vector<pair<int,int>>,int> freq(vector<int> &vol,int n){          //make a frequency vector
    vector<pair<int,int>> frq(n);
    int m=0;
    for(int i=0;i<n;i++){
        int k=i;
        int count=1;
        for(int j=i+1;j<n;j++){
            if(vol[i]==vol[j]){
                count++;
                k=j;
        }
    }
        i=k;
        frq[m].first=vol[i];
        frq[m++].second=count;
    }
    return {frq,m};
}
pair<vector<pair<int,int>>,int> grpfrq(vector<pair<int,int>> &frq,int m){
int max=frq[0].first*2;
vector<pair<int,int>> grp(max,{0,0});
int q=0;
for(int i=2;i<=max;i++){
    grp[q].first=i;
    for(int j=0;j<m;j++){
        int sec=i-frq[j].first;
        if(sec!=frq[j].first)
        {
                int p=j+1;
                while(p<m){
                    if(frq[p].first==sec){
                        grp[q].second+=min(frq[j].second,frq[p].second);
                        break;
                    }
                    p++;
                }
        }
        if(sec==frq[j].first){
            grp[q].second+=frq[j].second/2;
        }
    }
    q++;
}
return {grp,q};
}

pair<int,int> most_grp(vector<pair<int,int>> &grp,int q){
    int max_group=grp[0].second;
int z=0;
for(int i=0;i<q;i++){
    if(grp[i].second>max_group){
        max_group=grp[i].second;
        z=i;}
    if(grp[i].second==max_group&&grp[i].first<grp[z].first)
            z=i;}
            return {grp[z].second,grp[z].first};
}


int main()
{
    int t;
    while(t--){
    int n;
    cout<<"enter the number of vounteers: ";
    cin>>n;
    vector<int> vol(n);
    for(int i=0;i<n;i++){
        cin>>vol[i];
    }
    sort(vol,n);

    auto result=freq(vol,n);
    vector<pair<int,int>> frq=result.first;
    int size_frq=result.second;

    auto result1=grpfrq(frq,size_frq);
    vector<pair<int,int>> grp_freq=result1.first;
    int size_grp=result1.second;

    auto result3=most_grp(grp_freq,size_grp);
    cout<<"no of grps: "<<result3.first<<endl;
    cout<<"sum: "<<result3.second<<endl;
        }
            return 0;
}
