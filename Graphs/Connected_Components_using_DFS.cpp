#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> adj[10];
bool visited[10];
void dfs(int s)
{
	visited[s]=true;
	for(int i=0;i<adj[s].size();i++)
	{
		if(!visited[adj[s][i]])
			dfs(adj[s][i]);
	}
}
int main()
{
	int nodes,edges,x,y,connectedcomponents=0;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	{
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(int i=0;i<10;i++)
		visited[i]=false;
	for(int i=0;i<nodes;i++)
	{
		if(visited[i]==false)
		{
			dfs(i);
			connectedcomponents++;
		}
	}
	cout<<"Connected Components:"<<connectedcomponents<<endl;
}