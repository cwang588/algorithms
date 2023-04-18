#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,value;
}e[2000005];
bool cmp(edge x,edge y)
{
	return x.value<y.value;
}
int cnt,price[1005];
int fa[1005];
int getfa(int x)
{
	if(x!=fa[x])fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)fa[i]=i,scanf("%d",&price[i]);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				int tmp;
				scanf("%d",&tmp);
				++cnt;
				e[cnt].from=i;
				e[cnt].to=j;
				e[cnt].value=tmp+price[i]+price[j];
			}			
		sort(e+1,e+1+cnt,cmp);	
		int ans=0;
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
	}
	return 0;
}
