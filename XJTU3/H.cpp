#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[400005];
int Head[200005];
int cnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int num=1;num<=t;++num)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
	}
	return 0;
}
