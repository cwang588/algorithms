//kruskal
#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q; 
struct edge
{
	int from,to,value,next;
}e[1000005];
int head[50005],cnt;
void add(int a,int b,int c)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].value=c;
	e[cnt].next=head[a];
	head[a]=cnt;
}
bool usd[50005];
int father[50005];
int find(int x)
{
    if(father[x]!=x)
        father[x]=find(father[x]);
    return father[x];
}
void unionn(int a,int b)
{
    father[b]=a;
}
int jump[5005],x[5005],y[5005];
int main()
{
	int sum;
	scanf("%d",&sum);
	for(int i=1;i<=sum;++i)
		scanf("%d",&jump[i]);
	int n,Max=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		father[i]=i;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		for(int j=1;j<i;++j)
		{
			int d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			add(j,i,d);
			add(i,j,d);
			q.push(make_pair(d,cnt));
		}
	}
	int num=0,tot=0;
	while(num<n-1)
	{
		if(q.empty())
			return !printf("0");
		rr:int now=q.top().second;
		q.pop();
		int r1=find(e[now].from),r2=find(e[now].to);
		if(r1!=r2)
		{
			Max=max(Max,e[now].value);
			tot+=e[now].value;
			unionn(r1,r2);
		}
		else
			goto rr;
		++num;	
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		if(jump[i]*jump[i]>=Max)
			++ans;
	printf("%d",ans);
	return 0;
}
