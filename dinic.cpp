#include<cstdio>
using namespace std;
struct edge
{
	int from,to,value,next;
}e[200005];
int head[10005];
int cnt;
void add(int x,int y,int z)
{
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].next=head[e[cnt].from];
	head[e[cnt].from]=cnt;
	++cnt;
}
int main()
{
	int n,m,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t); 
	for(int i=1;i<=m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	
	return 0;
}
