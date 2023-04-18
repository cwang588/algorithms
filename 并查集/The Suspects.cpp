#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int fa[100005],sz[100005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	while(n)
	{
		memset(fa,0,sizeof(fa));
		memset(sz,0,sizeof(sz));
		for(int i=0;i<n;++i)fa[i]=i,sz[i]=1;
		for(int i=1;i<=m;++i)
		{
			int k,t;
			cin>>k;
			for(int j=1;j<=k;++j)
			{
				int x;
				cin>>x;
				if(j==1)t=x;
				else 
				{
					int r1=getfa(x),r2=getfa(t);
					if(r1!=r2)fa[r2]=r1,sz[r1]+=sz[r2];
				}
			}
		}
		cout<<sz[getfa(0)]<<endl;
		cin>>n>>m;
	}
	return 0;
}
