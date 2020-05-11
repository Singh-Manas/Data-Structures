#include<bits/stdc++.h>
using namespace std;
void topologicalsortutil(int v,vector<int> adj[],bool visited[],stack<int> &s)
{
	visited[v]=true;
	for(int i=0;i<(int)adj[v].size();i++)
		if(visited[adj[v][i]]==false)
			topologicalsortutil(adj[v][i],adj,visited,s);		//first traverse the whole graph
	s.push(v);													//then add the node to stack so that it is traveresed in reverse order
}
void topologicalsort(vector<int> adj[],int v)
{
	stack<int> s;												//stack to store nodes in reverse order of traversal
	bool *visited=new bool[v];
	memset(visited,false,v);
	for(int i=0;i<v;i++)
		if(visited[i]==false)
			topologicalsortutil(i,adj,visited,s);
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
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
	}
	topologicalsort(adj,v);
}