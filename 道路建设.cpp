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
int main()
{
	int n,m,Max;
	scanf("%d%d%d",&Max,&m,&n);
	for(int i=1;i<=n;++i)
		father[i]=i;
	for(int i=1;i<=m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
		q.push(make_pair(c,cnt));
	}
	int num=0,tot=0;
	while(num<n-1)
	{
		if(q.empty())
			return !printf("No");
		rr:int now=q.top().second;
		q.pop();
		int r1=find(e[now].from),r2=find(e[now].to);
		if(r1!=r2)
		{
			tot+=e[now].value;
			unionn(r1,r2);
		}
		else
			goto rr;
		++num;	
	}
	if(tot>Max)
		printf("No");
	else
		printf("Yes"); 
	return 0;
}
