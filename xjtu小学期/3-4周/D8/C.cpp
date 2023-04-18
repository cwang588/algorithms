#include<bits/stdc++.h>
using namespace std;
const long long mod=353442899;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q; 
struct edge
{
	int from,to,next;
	long long value1,value2;
}e[1000005];
bool cmp(edge a,edge b)
{
	if(a.value1!=b.value1)
		return a.value1<b.value1;
	return a.value2<b.value2; 
}
int head[500005],cnt;
void add(int a,int b,long long c,long long d)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].value1=c;
	e[cnt].value2=d;
	e[cnt].next=head[a];
	head[a]=cnt;
}
bool usd[500005];
int father[500005];
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
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		father[i]=i;
	for(int i=1;i<=m;++i)
	{
		int a,b;
		long long c,d;
		scanf("%d%d%lld%lld",&a,&b,&c,&d);
		add(a,b,c,d);
	}
	sort(e+1,e+m+1,cmp);
	int num=0,now=0;
	long long tot1=0,tot2=1;
	while(num<n-1)
	{
		rr:++now;
		int r1=find(e[now].from),r2=find(e[now].to);
		if(r1!=r2)
		{
			tot1+=e[now].value1;
			tot2=tot2*e[now].value2%mod;
			unionn(r1,r2);
		}
		else
			goto rr;
		++num;	
	}
	printf("%lld %lld",tot1,tot2);
	return 0;
}
