#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[200005];
int du[100005],Head[100005],cnt;
long long v[100005][3];
int index[100005];
int col[100005];
int anss[100005];
int n;
struct fuck
{
	int pos,col;
}shit[100005];
void update()
{
	for(int i=1;i<=n;++i)
		anss[i]=col[i]+1;
}
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs(int now,int pre,int pos)
{
	index[pos]=now;
	for(int i=Head[now];i;i=e[i].nxt)
		if(e[i].to!=pre)dfs(e[i].to,now,pos+1);
}
bool cmp(fuck a,fuck b)
{
	return a.pos<b.pos;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)cin>>v[i][0];
	for(int i=1;i<=n;++i)cin>>v[i][1];
	for(int i=1;i<=n;++i)cin>>v[i][2];
	for(int i=1;i<n;++i)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);	
		add(y,x);
		++du[x];	
		++du[y];
		if(du[x]>2)return !printf("-1\n");
		if(du[y]>2)return !printf("-1\n");	
	}
	int s;
	for(int i=1;i<=n;++i)
	{
		if(du[i]==1)
		{
			s=i;
			break;
		}
	}
	dfs(s,0,1);
	long long ans=9223372036854775805 ;
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
		{
			if(i!=j)
			{
				long long tep=0;
				col[1]=i;
				col[2]=j;
				tep+=v[index[1]][i]+v[index[2]][j];
				for(int k=3;k<=n;++k)
				{
					col[k]=3-col[k-1]-col[k-2];
					tep+=v[index[k]][col[k]];
				}
				if(tep<ans)
				{
					ans=tep;
					update();
				}
			}
		}
	for(int i=1;i<=n;++i)
	{
		shit[i].col=anss[i]; 
		shit[i].pos=index[i]; 
	}
	sort(shit+1,shit+1+n,cmp);
	cout<<ans<<endl;
	for(int i=1;i<=n;++i)cout<<shit[i].col<<' ';
	return 0;
}
