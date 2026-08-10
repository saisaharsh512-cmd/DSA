#include<iostream>
#include<vector>
using namespace std;

class PARKINGLOT {
    private:
    int n;
    vector<bool> arr;
    public:
    PARKINGLOT(int a);
    int insert();
    void remove(int a);
};
PARKINGLOT::PARKINGLOT(int a) {
    n=a;
    arr.resize(n,false);
}
int PARKINGLOT::insert() {
    int i=0;
    while(i<n) {
        if (arr[i]==false){
            arr[i]=true;
            return i;
        }
        i++;
    }
    return -1;
}

void PARKINGLOT::remove(int a){
    arr[a]=false;    
}

int main()
{
    int n,o;
    cin>>n>>o;
    PARKINGLOT v(n);
    while(o--){
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            cout<<"ans: "<<v.insert()<<endl;
            break;
        } 
        case 2:
        {
            int a;
            cin>>a;
            v.remove(a);
            break;
        }
    }
    }
    return 0;
}
