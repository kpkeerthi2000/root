#include<iostream>
#include"exception"

using namespace std;
class voter_age:public exception
{
public:
	float age;
	const char* what()
	{
	cout<<"not eligible";
	}
};


int main()
{
voter_age v;
cout<<"enter age";
cin>>v.age;
try
{
	if(v.age<18)
	throw(v);
	else if(v.age>117)
	cout<<"age limit exceeded";
	else
	cout<<"eligible";
}
catch(voter_age &va)
{
	va.what();
}
return 0;
}
