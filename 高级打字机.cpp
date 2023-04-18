#include<bits/stdc++.h>
using namespace std;
const int N=100000;
struct node
{
	int l,r,sum;
	char c;
}T[N*40];
int cnt;
int root[N];
int build(int l,int r,int node)
{
	node=++cnt;
	if(l==r)
	{
		T[node].sum=0;
		return node;
	}
	int m=(l+r)>>1;
	T[node].l=build(l,m,T[node].l);
	T[node].r=build(m+1,r,T[node].r);
	T[node].sum=T[T[node].l].sum+T[T[node].r].sum;
	return node;
} 
int modify(int l,int r,int node,int pos,char c)
{
	T[++cnt]=T[node];
	node=cnt;
	if(l==r)
	{
		T[node].c=c;
		T[node].sum=1;
		return node;
	}
	int m=(l+r)>>1;
	if(m>=pos)T[node].l=modify(l,m,T[node].l,pos,c);
	else T[node].r=modify(m+1,r,T[node].r,pos,c);
	T[node].sum=T[T[node].l].sum+T[T[node].r].sum;
	return node;	
}
char query(int l,int r,int node,int k)
{
	if(l==r)return T[node].c;
	int m=(l+r)>>1;
	if(T[T[node].l].sum>=k)return query(l,m,T[node].l,k);
	else return query(m+1,r,T[node].r,k-T[T[node].l].sum);
}
int main()
{
	ios::sync_with_stdio(false);
	int n;	
	cin>>n;
	int tot=0;
	root[0]=build(1,n,root[0]);
	int now=0;
	for(int i=1;i<=n;++i)
	{
		char c;
		cin>>c;
		if(c=='T')
		{
			char x;
			cin>>x;
			++now,++tot;
			root[now]=modify(1,n,root[now-1],tot,x);
		}
		else if(c=='Q')
		{
			int x;
			cin>>x;
			cout<<query(1,n,root[now],x)<<endl;
		}
		else
		{
			int x;
			cin>>x;
			++now;
			root[now]=root[now-x-1];
		}
	}
	return 0;
}
