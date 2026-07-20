#include<iostream>
using namespace std;

int main()
{
int age;
cout<<"Hello world"<< endl;
cout<<"buddy!! enter your age:";
cin>>age;
cout<<"man you are "<<age<<" old, damn!"<<endl;
int *ptr;
ptr=&age;
int age1;
cout<<"what is your fathers age bro:";
cin>>age1;
int *ptr1;
ptr1=&age1;
cout<<"okay so your fathers age is "<< age1<<endl;
cout<<"address of u: "<<ptr<<endl;
cout<<"address of ur father: "<<ptr1<<endl;
cout<<"subtraction of age: "<<ptr-ptr1<<endl;
cout<<"addition by a scalar to the address: "<<ptr+1<<endl;
ptr1++;
ptr1--;
cout<<"increment in the pointers: "<<ptr1<<endl;
// traversing of array using pointers OMG!!
int a[6]={1,2,3,4,5,6};
int *ptr3;
ptr3=a;
for ( int i=0;i<6;i++)
{
	cout<<*ptr3<<endl;
	ptr3++;
}

return 0;
}
