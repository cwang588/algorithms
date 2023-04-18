#include<cstdio>
#include<set>
using namespace std;
set<int>s;
int col[10005];
struct edge
{
	int from,to,next;
}e[500005];
int head[10005];
int cnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		s.clear();
		for(int j=1;j<=n;++j)	
		{
			scanf("%d",&col[j]);
			s.insert(col[j]);
		}
		if(s.size()!=k)
		{
			printf("No\n");
			continue;
		}
		bool he=true;
		for(int j=1;j<=cnt;++j)
		{
			if(col[e[j].from]==col[e[j].to])
			{
				he=false;
				break;
			}
		}
		if(!he)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
