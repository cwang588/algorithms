#include<cstdio>
#include<queue>
#include<utility>
#define INF 2147483647
using namespace std;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
bool aa1[500005],aa2[500005];
int head1[10005],head2[10005],head3[10005],head4[10005];
int dis1[10005],dis2[10005],dis3[10005],dis4[10005];
bool usd1[10005],usd2[10005],usd3[10005],usd4[10005];
int cnt1,cnt2,cnt3,cnt4;
struct edge
{
	int to,from,value,next;
}e1[500005],e2[500005],e3[500005],e4[500005];
int num1,num2;
int ans1[5005],ans2[5005];
void add1(int x,int y,int z)
{
	++cnt1;
	e1[cnt1].from=x;
	e1[cnt1].to=y;
	e1[cnt1].value=z;
	e1[cnt1].next=head1[x];
	head1[x]=cnt1;
}
void add2(int x,int y,int z)
{
	++cnt2;
	e2[cnt2].from=x;
	e2[cnt2].to=y;
	e2[cnt2].value=z;
	e2[cnt2].next=head2[x];
	head2[x]=cnt2;
}
void dfs1(int now)
{
	ans1[++num1]=now;
	for(int i=head3[now];i;i=e3[i].next)
	{
		if(aa1[i])
		{
			dfs1(e3[i].to);
			break;
		}
	}
}
void dfs2(int now)
{
	ans2[++num2]=now;
	for(int i=head4[now];i;i=e4[i].next)
	{
		if(aa2[i])
		{
			dfs2(e4[i].to);
			break;
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y,z,p,q;
		scanf("%d%d%d%d%d",&x,&y,&z,&q,&p);
		++x;
		++y;
		if(z==0)
		{
			add1(x,y,p);
			add2(x,y,q);
			add2(y,x,q);
			add1(y,x,p);
		}
		else
		{
			add1(x,y,p);
			add2(x,y,q);
		}
	}
	int s,ss;
	scanf("%d%d",&s,&ss);
	++s;
	++ss;
	for(int i=1;i<=n;++i)
		dis1[i]=dis2[i]=dis3[i]=dis4[i]=INF;
	dis1[s]=dis2[s]=dis3[s]=dis4[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usd1[now])
		{
			usd1[now]=true;
			for(int i=head1[now];i;i=e1[i].next)
			{
				if(dis1[e1[i].to]>dis1[e1[i].from]+e1[i].value)
					dis1[e1[i].to]=dis1[e1[i].from]+e1[i].value;
				q.push(make_pair(dis1[e1[i].to],e1[i].to));
			}
		}
	}
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usd2[now])
		{
			usd2[now]=true;
			for(int i=head2[now];i;i=e2[i].next)
			{
				if(dis2[e2[i].to]>dis2[e2[i].from]+e2[i].value)
					dis2[e2[i].to]=dis2[e2[i].from]+e2[i].value;
				q.push(make_pair(dis2[e2[i].to],e2[i].to));
			}
		}
	}
	for(int i=1;i<=cnt1;++i)
		if(dis1[e1[i].to]-dis1[e1[i].from]==e1[i].value)
		{
			++cnt3;
			e3[cnt3].from=e1[i].from;
			e3[cnt3].to=e1[i].to;
			e3[cnt3].value=1;
			e3[cnt3].next=head3[e1[i].from];
			head3[e1[i].from]=cnt3;
		}
	for(int i=1;i<=cnt2;++i)
		if(dis2[e2[i].to]-dis2[e2[i].from]==e2[i].value)
		{
			++cnt4;
			e4[cnt4].from=e2[i].from;
			e4[cnt4].to=e2[i].to;
			e4[cnt4].value=1;
			e4[cnt4].next=head4[e2[i].from];
			head4[e2[i].from]=cnt4;
		}	
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usd3[now])
		{
			usd3[now]=true;
			for(int i=head3[now];i;i=e3[i].next)
			{
				if(dis3[e3[i].to]>dis3[e3[i].from]+e3[i].value)
					dis3[e3[i].to]=dis3[e3[i].from]+e3[i].value;
				q.push(make_pair(dis3[e3[i].to],e3[i].to));
			}
		}
	}
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usd4[now])
		{
			usd4[now]=true;
			for(int i=head4[now];i;i=e4[i].next)
			{
				if(dis4[e4[i].to]>dis4[e4[i].from]+e4[i].value)
					dis4[e4[i].to]=dis4[e4[i].from]+e4[i].value;
				q.push(make_pair(dis4[e4[i].to],e4[i].to));
			}
		}
	}
	for(int i=1;i<=cnt3;++i)
		if(dis3[e3[i].to]-dis3[e3[i].from]==1)
			aa1[i]=true;
	for(int i=1;i<=cnt4;++i)
		if(dis4[e4[i].to]-dis4[e4[i].from]==1)
			aa2[i]=true;
	dfs1(s);
	dfs2(s);
	if(num1==num2)
	{
		bool yy=true;
		for(int i=1;i<=num1;++i)
			if(ans1[i]!=ans2[i])
			{
				yy=false;
				break;
			}
		if(yy)
		{
			printf("Time = %d; Distance = %d: ",dis1[n],dis2[n]);
			for(int i=1;i<num1;++i)
				printf("%d => ",ans1[i]-1);
			printf("%d",ans1[num1]-1);
			return 0;
		}
	}
	printf("Time = %d: ");
	for(int i=1;i<num1;++i)
		printf("%d => ",ans1[i]-1);
	printf("%d\n",ans1[num1]-1);
	printf("Distance = %d: ");
	for(int i=1;i<num2;++i)
		printf("%d => ",ans2[i]-1);
	printf("%d",ans2[num2]-1);
	return 0;
}
