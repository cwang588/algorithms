#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int fa[100005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int now=n;
		for(int i=1;i<=n;++i)fa[i]=i;
		for(int i=1;i<=m;++i)
		{
			int x,y;
			cin>>x>>y;
			int r1=getfa(x),r2=getfa(y);
			if(r1!=r2)fa[r1]=r2,--now;
		}
		cout<<now<<endl;
	}
	return 0;
}
