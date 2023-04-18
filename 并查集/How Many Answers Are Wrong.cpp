#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int fa[200005];
long long value[200005];
int getfa(int x)
{
	if(fa[x]!=x)
	{
		int t=fa[x];
		fa[x]=getfa(fa[x]);
		value[x]+=value[t];
	}
	return fa[x];
}
void Merge(int x,int y,long long z)
{
	int r1=getfa(x),r2=getfa(y);
	if(r1>r2)swap(x,y),swap(r1,r2),z*=-1;
	if(r1!=r2)
	{
		fa[r1]=r2;
		value[r1]=value[y]+z-value[x];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n+1;++i)fa[i]=i;
	int num=0;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		long long z;
		cin>>x>>y>>z;
		++y;
		int r1=getfa(x),r2=getfa(y);
		if(r1!=r2)Merge(x,y,z);
		else 
		{
			if(value[x]-value[y]!=z)++num;
		}
	}
	cout<<num<<endl;
	return 0;
} 
