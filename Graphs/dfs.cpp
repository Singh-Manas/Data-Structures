#include<bits/stdc++.h>
using namespace std;
map<int,int> parent;						//map to store parent of node
void dfs(vector<int> adj[],int s)
{
	cout<<s<<" ";
	for(int i=0;i<(int)adj[s].size();i++)
	{
		if(parent.find(adj[s][i])==parent.end()) //checking if node is already visited or not by checking if this node has parent in map
		{
			parent[adj[s][i]]=s;			//updating parent of node
			dfs(adj,adj[s][i]);				//recursively calling on that node
		}
	}
}
int main()
{
	int v,e;
	cin>>v>>e;
	vector<int> *adj=new vector<int>[v];	//creating adjacency list of size v
	for(int i=0;i<e;i++)					//taking input of graph
	{
		int f,s;
		cin>>f>>s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}
	// for(int i=0;i<v;i++)							
	// {
	// 	for(int j=0;j<(int)adj[i].size();j++)
	// 		cout<<adj[i][j]<<" ";
	// 	cout<<endl;
	// }
	// bool *visited=new bool[v];		//visited array to check if node has been visited or not
	// for(int i=0;i<v;i++)
	// 	visited[i]=false;
	parent[0]=-1;
	dfs(adj,0);
	cout<<endl;
	map<int,int>::iterator it;						//showing parent of each node
	for(it=parent.begin();it!=parent.end();it++)
		cout<<it->first<<"->"<<it->second<<endl;
}