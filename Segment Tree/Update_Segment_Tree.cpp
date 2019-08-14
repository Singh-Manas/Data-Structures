#include<bits/stdc++.h>
using namespace std;
void buildtree(int a[],int tree[],int start,int end,int treenode)
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
int main()
{
	int a[]={1,2,3,4,5};
	int *tree=new int[10];
	buildtree(a,tree,0,4,1);
	for(int i=1;i<10;i++)
		cout<<tree[i]<<" ";
	cout<<endl;
	updatetree(a,tree,0,4,1,2,10);
	for(int i=1;i<10;i++)
		cout<<tree[i]<<" ";
	return 0;
}