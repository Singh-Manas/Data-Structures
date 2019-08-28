#include<bits/stdc++.h>
using namespace std;
bool bfs(int**g,int n,int sv,int ev)
{
	queue<int> q;
	bool*visited;
	visited=new bool[n];
	for(int i=0;i<n;i++)
		visited[i]=false;
	q.push(sv);
	visited[sv]=true;
	int top;
	while(!q.empty())
	{
		top=q.front();
		q.pop();
		if(top==ev)
			return true;
		for(int i=0;i<n;i++)
		{
			if(g[top][i]==1)
			{
				if(!visited[i])
				{
					q.push(i);
					visited[i]=true;
				}
			}
		}
	}
	return false;
}
int main()
{
	int n;
	cout<<"How many nodes:";
	cin>>n;
	int e;
	cout<<"How many edges:";
	cin>>e;
	cout<<"Enter edges:";
	int**g;
	g=new int*[n];
	for(int i=0;i<n;i++)
		g[i]=new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			g[i][j]=0;
	for(int i=0;i<e;i++)
	{
		int sv,ev;
		cin>>sv>>ev;
		g[sv][ev]=1;
		g[ev][sv]=1;
	}
	cout<<"Enter Starting and Ending vertex for finding path:";
	int sv,ev;
	cin>>sv>>ev;
	bool ans=bfs(g,n,sv,ev);
	if(ans)
		cout<<"Path exists";
	else
		cout<<"Path doesn't exist";
}