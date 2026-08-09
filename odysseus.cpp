#include<iostream>
using namespace std;
    //lets create an array of classes
    class FLEETMANAGER{
        private:
        int count;
        int shipID[100];
        int crewSize[100];
        int foodSupply[100];

        public:
        FLEETMANAGER();
        void input(int a,int b,int c);
        void eliminate(int a);
        int largest();
        void print();
        int sum();
        int crewlimit(int a);
    };
    
    FLEETMANAGER::FLEETMANAGER()
    {
        count=0;
        for(int i=0;i<100;i++){
        shipID[i]=0;
        crewSize[i]=0;
        foodSupply[i]=0;}
    }
    void FLEETMANAGER::input(int a,int b,int c){
        shipID[count]=a;
        crewSize[count]=b;
        foodSupply[count]=c;
        count++;
    }
    void FLEETMANAGER::print(){
        for(int i=0;i<count;i++){
        cout<<" "<<shipID[i]<<" "<<crewSize[i]<<" "<<foodSupply[i]<<endl;
        }
    }
    void FLEETMANAGER::eliminate(int a)
    {
        int pos=-1;
       for(int i=0;i<count;i++){
        if(shipID[i]==a){
            pos=i;
        }}
        if(pos!=-1){
            for(int i=pos;i<count;i++)
            {
                shipID[i]=shipID[i+1];
                crewSize[i]=crewSize[i+1];
                foodSupply[i]=foodSupply[i+1];
            }
            count--;
        }
        else
            cout<<"ENTER VALID ID";    
    }
    int FLEETMANAGER::largest(){
        int max=crewSize[0];
        int maxID=shipID[0];
        int k=0;
        for(int i=0;i<count;i++){
            if(crewSize[i]>max){
                max=crewSize[i];
                k=i;
            }
            if(crewSize[i]==max&&shipID[k]>shipID[i])
                k=i;
        }
        return shipID[k];
    }
    int FLEETMANAGER::sum(){
        int sum=0;
        for(int i=0;i<count;i++)
        {
            sum+=foodSupply[i];
        }
        return sum;
    }
    int FLEETMANAGER::crewlimit(int a)
    {
        int total=0;
        for(int i=0;i<count;i++){
        if(a<=crewSize[i]){
            total++;
        }
        }
        return total;
    }
    int main()
    {
        int t;
        cin>>t;
        while (t--) {
            FLEETMANAGER p;
            int n;
            cout<<"Enter the number of operations:";
            cin>>n;
            while (n--) {
                int ch;
                cout<<"enter your choice: ";
                cin>>ch;
                switch(ch){
                    case 1: {
                        int a,b,c;
                        cout<<"Enter crewID,crewSize,crewSupply: ";
                        cin>>a>>b>>c;
                        p.input(a,b,c);
                        p.print();
                        break;
                    }
                    case 2: {
                        int d;
                        cout<<"Enter the ID to be removed: ";
                        cin>>d;
                        p.eliminate(d);
                        p.print();
                        break;
                    }
                    case 3: {
                        cout<<p.largest()<<endl;
                        break;
                    }
                    case 4: {
                        cout<<p.sum()<<endl;
                        break;
                    }
                    case 5: {
                        int e;
                        cout<<"enter the crew limit: ";
                        cin>>e;
                        cout<<p.crewlimit(e)<<endl;
                        break;
                    }
                    default: ;
                }
            }
        }
        return 0;
    }