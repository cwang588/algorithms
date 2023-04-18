#include<cstdio>
#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
struct edge
{
	int from,to,value,next;
}e[100005];
struct lian
{
	int x,y,l;
}ll[50005];
int ans;
int head[50005],cnt;
int n,m;
void add(int x,int y,int z)
{
	++cnt;	
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].next=head[e[cnt].from];
	head[e[cnt].from]=cnt;
}
int main()
{
	srand(19260817);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	int cishu=1e6/m;
	
	return 0;
}
