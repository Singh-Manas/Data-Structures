#include<bits/stdc++.h>
using namespace std;
void buildtree(int*a,int*tree,int start,int end,int treenode)
{
	if(start==end)
	{
		tree[treenode]=a[start];
		return;
	}
	int mid=(start+end)/2;
	buildtree(a,tree,start,mid,2*treenode);
	buildtree(a,tree,mid+1,end,2*treenode+1);
	tree[treenode]=tree[2*treenode]+tree[2*treenode+1];
}
void updatetree(int*a,int*tree,int start,int end,int treenode,int index,int value)
{
	if(start==end)
	{
		a[index]=value;
		tree[treenode]=value;
		return;
	}
	int mid=(start+end)/2;
	if(index>mid)
		updatetree(a,tree,mid+1,end,2*treenode+1,index,value);
	else
		updatetree(a,tree,start,mid,2*treenode,index,value);
	tree[treenode]=tree[2*treenode]+tree[2*treenode+1];
}
int query(int*tree,int start,int end,int treenode,int left,int right)
{
	if(start>right||end<left)
		return 0;
	if(start>=left && end<=right)
		return tree[treenode];
	int mid=(start+end)/2;
	int ans1=query(tree,start,mid,2*treenode,left,right);
	int ans2=query(tree,mid+1,end,2*treenode+1,left,right);
	return ans1+ans2;
}
void printtree(int*tree,int n,int start)
{
	for(int i=start;i<n;i++)
		cout<<tree[i]<<" ";
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	int*a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int* tree=new int[2*n];
	buildtree(a,tree,0,n-1,1);
	printtree(tree,2*n,1);
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int index,value;
		cin>>index>>value;
		updatetree(a,tree,0,n-1,1,index,value);
		printtree(tree,2*n,1);
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int left,right;
		cin>>left>>right;
		int ans=query(tree,0,n-1,1,left,right);
		cout<<ans<<" ";
	}
}