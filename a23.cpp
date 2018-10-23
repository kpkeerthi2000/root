#include<iostream>
#include"exception"
using namespace std;
int main()
{
float amt;
cout<<"enter the withdraw amount";
cin>>amt;
try
{
	if(amt>=5000)
	{
		throw("withdraw is not possible");
	}
	else
	{
		cout<<"withdraw is possible"<<endl; 
	}
}
catch(const char *s)
{
	cout<<s<<endl;
}
return 0;
}

