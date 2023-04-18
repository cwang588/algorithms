#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
set<int>s;
struct edge
{
	int from,to,next;
}e[400005];
int head[505];
int cnt;
int col[505];
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
	int num;
	scanf("%d",&num);
	for(int i=1;i<=num;++i)
	{
		int sum=0;
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&col[j]);
			s.insert(col[j]);
		}
		if(s.size()!=k)
		{
			printf("No\n");
			s.clear();
			continue;
		}
		s.clear();
		bool zq=true;
		for(int j=1;j<=cnt/2;++j)
			if(col[e[2*j].from]==col[e[2*j].to])
			{
				zq=false;
				break;
			}		
		if(zq)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
