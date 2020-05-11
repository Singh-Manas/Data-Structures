#include<bits/stdc++.h>
using namespace std;
bool iscyclicutil(int v,vector<int> adj[],bool visited[],int parent)
{
	visited[v]=true;
	for(int i=0;i<(int)adj[v].size();i++)
	{
		if(visited[adj[v][i]]==false)		//for every edge from node check if there is cycle from its child
		{
			if(iscyclicutil(adj[v][i],adj,visited,v))
				return true;
		}	
		else if(adj[v][i]!=parent)			//check if node is traversed before and it is not direct parent then there is a cycle 
			return true;
	}
	return false;
}
bool iscyclic(vector<int> adj[],int v)
{
	bool *visited=new bool[v];
	memset(visited,false,v);
	for(int u=0;u<v;u++)			//loop in case there is a disconnected graph
		if(visited[u]==false)
			if(iscyclicutil(u,adj,visited,-1))
				return true;
	return false;
}
int main()
{
	int v,e;
	cin>>v>>e;
	vector<int> *adj=new vector<int>[v];
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}
	if(iscyclic(adj,v))
		cout<<"There is a cycle";
	else
		cout<<"There is not a cycle";
}