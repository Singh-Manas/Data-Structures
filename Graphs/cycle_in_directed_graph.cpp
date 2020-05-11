#include<bits/stdc++.h>
using namespace std;
bool iscyclicutil(int v,vector<int> adj[],bool visited[],bool stack[])
{
	visited[v]=true;
	stack[v]=true;
	for(int i=0;i<(int)adj[v].size();i++)
	{
		if(visited[adj[v][i]]==false)		//for every edge from node check if there is cycle from its child
		{
			if(iscyclicutil(adj[v][i],adj,visited,stack))
				return true;
		}
		else if(stack[adj[v][i]])			//check if node is traversed before and it is not in the recursive path then there is a cycle
			return true;
	}
	stack[v]=false;					//make recursive path as false
	return false;
}
bool iscyclic(vector<int> adj[],int v)
{
	bool *visited=new bool[v];
	memset(visited,false,v);
	bool *stack=new bool[v];
	memset(stack,false,v);
	for(int u=0;u<v;u++)
		if(visited[u]==false)
			if(iscyclicutil(u,adj,visited,stack))
				return true;
	return false;
}
int main()
{
	int v,e;
	cin>>v>>e;
	vector<int>*adj=new vector<int>[v];
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		adj[f].push_back(s);
		//adj[s].push_back(f);
	}
	if(iscyclic(adj,v))
		cout<<"There is a cycle";
	else
		cout<<"There is not a cycle";
}