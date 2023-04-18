#include<cstdio>
#include<iostream>
using namespace std;
int dp[300005];
struct edge
{
	int from,to,next;
}e[600005];
int head[300005],cnt;
void add(int a,int b)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].next=head[e[cnt].from];
	head[e[cnt].from]=cnt;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	string t;
	cin>>t;
	for(int i=1;i<n;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	
	return 0;
}
