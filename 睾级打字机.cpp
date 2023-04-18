#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct node
{
	int l,r;
	char c;
}T[N*40];
int root[N],cnt;
int build(int l,int r,int node)
{
	if(l==r)return node;
	int m=(l+r)>>1;
	T[node].l=build(l,m,T[node].l);
	T[node].r=build(m+1,r,T[node].r);
	return node;
}
int modify(int l,int r,int node,int pos,char c)
{
	T[++cnt]=T[node];
	node=cnt;
	if(l==r)
	{
		T[node].c=c;
		return node;
	}
	int m=(l+r)>>1;
	if(m>=pos)T[node].l=modify(l,m,T[node].l,pos,c);
	else T[node].r=modify(m+1,r,T[node].r,pos,c);
	return node;
}
char query(int l,int r,int node,int pos)
{
	if(l==r)return T[node].c;
	int m=(l+r)>>1;
	if(m>=pos)return query(l,m,T[node].l,pos);
	else return query(m+1,r,T[node].r,pos);
}
int sum[N];
int main()
{
	ios::sync_with_stdio(false);
	int n; 
	cin>>n;
	int tot=0;
	root[0]=build(1,n,0);
	for(int i=1;i<=n;++i)
	{
		char c;
		cin>>c;
		if(c=='T')
		{
			char t;
			cin>>t;
			++tot;
			sum[tot]=sum[tot-1]+1;
			root[tot]=modify(1,n,root[tot-1],sum[tot],t);
		}
		else if(c=='U')
		{
			int x;
			cin>>x;
			++tot;
			sum[tot]=sum[tot-x-1];
			root[tot]=root[tot-x-1];
		}
		else
		{
			int x;
			cin>>x;
			cout<<query(1,n,root[tot],x)<<endl;
		}
	}
	
	return 0;
}
