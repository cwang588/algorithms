#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct edge
{
	int from,to,value;
}e[100005];
bool cmp(edge x,edge y)
{
	return x.value<y.value;
}
int cnt;
int fa[100005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
} 
int main()
{
	ios::sync_with_stdio(false);
	int n; 
	cin>>n;
	while(n)
	{
		cnt=0;
		for(int i=1;i<=n;++i)fa[i]=i;
		for(int i=1;i<n;++i)
		{
			char now;
			cin>>now;
			int tmp=(int)(now-'A'+1);
			int k;
			cin>>k;
			for(int j=1;j<=k;++j)
			{
				char to;
				int value;
				cin>>to>>value;
				++cnt;
				e[cnt].from=tmp;
				e[cnt].to=(int)(to-'A'+1);
				e[cnt].value=value;
			}
		}
		int ans=0;
		sort(e+1,e+1+cnt,cmp);
		for(int i=1;i<=cnt;++i)
		{
			int r1=getfa(e[i].from),r2=getfa(e[i].to);
			if(r1!=r2)
			{
				ans+=e[i].value;
				Merge(e[i].from,e[i].to);
			}
		}
		printf("%d\n",ans);
		cin>>n;
	}
	return 0;
}
