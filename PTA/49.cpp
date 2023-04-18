#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
struct edge
{
	int from,to,value,next;
}e1[500005],e2[500005];
int cnt1,cnt2,head1[505],head2[505],last1[505],last2[505],num1[505],num2[505],ans1[505],ans2[505],sum1,sum2,dis1[505],dis2[505];
bool usd1[505],usd2[505];
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
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		add1(a,b,d);
		add2(a,b,e);
		if(!c)
		{
			add1(b,a,d);
			add2(b,a,e);
		}
	}
	for(int i=0;i<n;++i)
	{
		dis1[i]=dis2[i]=num2[i]=num1[i]=INF;
		last1[i]=last2[i]=-1;
	}
	int s,ss;
	scanf("%d%d",&s,&ss);
	dis1[s]=dis2[s]=0;
	num1[s]=1;
	num2[s]=0;
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
				if(dis1[e1[i].to]==INF||dis1[e1[i].to]>dis1[e1[i].from]+e1[i].value)
				{
					dis1[e1[i].to]=dis1[e1[i].from]+e1[i].value;
					q.push(make_pair(dis1[e1[i].to],e1[i].to));
					last1[e1[i].to]=e1[i].from;
					num1[e1[i].to]=num1[e1[i].from]+1;
				}
				if(dis1[e1[i].to]==dis1[e1[i].from]+e1[i].value)
				{
					if(num1[e1[i].to]>num1[e1[i].from]+1)
					{
						last1[e1[i].to]=e1[i].from;
						num1[e1[i].to]=num1[e1[i].from]+1;
					}
				}
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
				if(!usd2[e2[i].to])
				{
					if(dis2[e2[i].to]==INF||dis2[e2[i].to]>dis2[e2[i].from]+e2[i].value)
					{
						dis2[e2[i].to]=dis2[e2[i].from]+e2[i].value;
						q.push(make_pair(dis2[e2[i].to],e2[i].to));
						last2[e2[i].to]=e2[i].from;
						num2[e2[i].to]=num2[e2[i].from]+e1[i].value;
					}
				}
				if(dis2[e2[i].to]==dis2[e2[i].from]+e2[i].value)
				{
					if(num2[e2[i].to]>num2[e2[i].from]+e1[i].value)
					{
						last2[e2[i].to]=e2[i].from;
						num2[e2[i].to]=num2[e2[i].from]+e1[i].value;
					}
				}
			}
		}
	}	
	for(int i=ss;i!=-1;i=last1[i])
		ans1[++sum1]=i;
	for(int i=ss;i!=-1;i=last2[i])
		ans2[++sum2]=i;
	if(sum1==sum2)
	{
		bool xt=true;
		for(int i=1;i<=sum1;++i)
			if(ans1[i]!=ans2[i])
			{
				xt=false;
				break;
			}
		if(xt)
		{
			printf("Time = %d; Distance = %d: ",dis2[ss],dis1[ss]);
			for(int i=sum1;i>1;--i)
				printf("%d => ",ans1[i]);
			printf("%d\n",ans1[1]);
			return 0;
		}
	}		
	printf("Time = %d: ",dis2[ss]);
	for(int i=sum2;i>1;--i)
		printf("%d => ",ans2[i]);
	printf("%d\n",ans2[1]);
	printf("Distance = %d: ",dis1[ss]);
	for(int i=sum1;i>1;--i)
		printf("%d => ",ans1[i]);
	printf("%d\n",ans1[1]);
	return 0;
}

