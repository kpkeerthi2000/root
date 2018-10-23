#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int>v[],int a,int b)
{
    v[a].push_back(b);
}
void bfs(vector<int>v[],int start,int n)
{
   
    bool a[n];
    
    memset(a,false,sizeof(a));
    queue<int>q;
    a[start]=true;
    q.push(start);
    //cout<<q.front();
    vector<int>::iterator it;
    while(!q.empty())
    {
        int s=q.front();
        cout<<s;
        q.pop();
        for(it=v[s].begin();it!=v[s].end();it++)
        {
            if(a[*it]==false)
            {
                a[*it]=true;
                q.push(*it);
            }
        }
    }
}
int main() 
{
	vector<int>v[5];
	int n=sizeof(v)/sizeof(v[0]);
	//cout<<n;
	addEdge(v,0, 1); 
    addEdge(v,0, 2); 
    addEdge(v,1, 2); 
    addEdge(v,2, 0); 
    addEdge(v,2, 3); 
    addEdge(v,3, 3); 
	bfs(v,2,n);
	return 0;
}
