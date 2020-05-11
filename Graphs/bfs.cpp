#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[],int s,int level[],bool visited[])
{
	queue<int> q;			//create queue for storing nodes in level order
	q.push(s);	
	level[s]=0;				//update level of source to 0
	visited[s]=true;		//mark source as visited
	int top;
	while(!q.empty())		
	{	
		top=q.front();
		cout<<top<<" ";
		q.pop();
		for(int i=0;i<(int)adj[top].size();i++)
		{
			if(visited[adj[top][i]]==false)				//for every top element add child to queue and update visited and level array
			{
				level[adj[top][i]]=level[top]+1;
				q.push(adj[top][i]);
				visited[adj[top][i]]=true;
			}
		}
	}
	cout<<endl;
}
int main()
{
	int v,e;
	cin>>v>>e;
	vector<int> *adj=new vector<int> [v];
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}
	int *level=new int[v];
	memset(level,-1,v);
	bool *visited=new bool[v];
	memset(visited,false,v);
	bfs(adj,0,level,visited);
	for(int i=0;i<v;i++)
		cout<<i<<"->"<<level[i]<<endl;
}