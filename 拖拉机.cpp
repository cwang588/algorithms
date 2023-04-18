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
int gz[1005][1005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&gz[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=2;j<=n;++j)
		{
			add(j-1+(i-1)*n,j+(i-1)*n,abs(gz[i][j]-gz[i][j-1]));
			add(j+(i-1)*n,j-1+(i-1)*n,abs(gz[i][j]-gz[i][j-1]));
			q.push(make_pair(abs(gz[i][j]-gz[i][j-1]),cnt));
		}
	for(int i=2;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			add(j+i*n,j+(i-1)*n,abs(gz[i][j]-gz[i-1][j]));
			add(j+(i-1)*n,j+i*n,abs(gz[i][j]-gz[i-1][j]));
			q.push(make_pair(abs(gz[i][j]-gz[i-1][j]),cnt));
		}	
	for(int i=1;i<=n*n;++i)
		father[i]=i;
	int Max=0;
	int num=0,tot=0;
	while(num<n*n-1)
	{
		if(q.empty())
			return !printf("orz");
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
		Max=max(Max,e[now].value);
		if(num==(n*n+1)/2)
			return !printf("%d",Max);
	}
	return 0;
}
