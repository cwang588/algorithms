#include<bits/stdc++.h>
using namespace std;
vector<int>v[100005];
struct edge
{
	int from,to,nxt;
}e[200005];
int Head[100005],cnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs(int now,int pre)
{
	printf("%d ",now);
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		v[now].push_back(to);
	}
	sort(v[now].begin(),v[now].end());
	vector<int>::iterator it;
	for(it=v[now].begin();it!=v[now].end();++it)
		dfs(*it,now);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	return 0;
}
