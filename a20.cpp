#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define MAX 100
class PQUEUE
{
public:
string a[MAX];
int b[MAX];
int front,rear;
void enqueue(string,int);
void dequeue();
void disp();
void priority(string ,int);
PQUEUE ()
{
front=rear=0;
}
};
void PQUEUE::enqueue(string n,int p)
{
	if(front==0&&rear==0)
	{
	rear=rear+1;
	//strcpy(a[rear],n);
a[rear]=n;	
b[rear]=p;
	}
	else 
	priority(n,p);
}
void PQUEUE::priority(string n,int p)
{
	int i=0,j;
	for(i=front+1;i<=rear;i++)
	{
		if(p<b[i])
		{
			for(j=rear+1;j>i;j--)
			{
				//strcpy(a[j],a[j-1]);
a[j]=a[j-1];				
b[j]=b[j-1];
			}
rear=rear+1;
			//strcpy(a[i],n);
a[i]=n;			
b[i]=p;
			return;
		}
	}
rear=rear+1;
		//strcpy(a[i],n);
a[i]=n;		
b[i]=p;
	
}
void PQUEUE::dequeue()
{
if(front==rear)
cout<<"queue is empty";
else
{
front=front+1;
cout<<"\n"<<a[front]<<"is removed"<<endl;
}
}
void PQUEUE::disp()
{
	for(int k=front+1;k<=rear;k++)
	{
		cout<<" "<<a[k]<<" "<<b[k]<<endl;
	}
}
int main()
{
	PQUEUE q;
int p,c;
string s;
	cout<<"1.enqueue\n2.dequeue\n3.display4.exit";
	while(1)
	{
	cout<<"enter choice";
	cin>>c;
	switch(c)
	{
		case 1:{cout<<"enter customer name and priority";
			cin>>s;	cin>>p;
			q.enqueue(s,p);
			break;
			}
		case 2:q.dequeue();break;
		case 3:q.disp();break;
		case 4:return 0;
	}
	}
}
