#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef pair<int, int> pii;
struct gs
{
	int a[7],b[7];
}g[maxn];
int c[maxn];
int ans;
priority_queue<pii,vector<pii>,greater<pii> >q[7];
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int _read()
{
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
int n,m;
void dfs(int now)
{
	if(now==m)
	{
		while(!q[now].empty())
		{
			pii t=q[now].top();
			if(t.first>c[now])
				return;
			q[now].pop();
			++ans;
			for(int i=1;i<=m;++i)
				c[i]+=g[t.second].b[i];
		}
		return;
	}
	while(!q[now].empty())
	{
		pii t=q[now].top();
		if(t.first>c[now])
			break;
		q[now].pop();
		q[now+1].push(make_pair(g[t.second].a[now+1],t.second));	
	}
	dfs(now+1);
}
int main()
{
	int t;
	t=_read();
	while(t--)
	{
		memset(c,0,sizeof(c));
		ans=0,n=_read(),m=_read();
		for(int i=1;i<=m;++i)
			c[i]=_read();
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				g[i].a[j]=_read();
			for(int j=1;j<=m;++j)
				g[i].b[j]=_read();			
		}
		for(int i=1;i<=n;++i)
			q[1].push(make_pair(g[i].a[1],i));
		while(!q[1].empty()||!q[2].empty()||!q[3].empty()||!q[4].empty()||!q[5].empty())
		{
			int tt=ans;
			dfs(1);
			if(ans==tt)
				break;
		}
		printf("%d\n",ans);
		for(int i=1;i<m;++i)
			printf("%d ",c[i]);
		printf("%d\n",c[m]);
		for(int i=1;i<=m;++i)
			while(!q[i].empty())
				q[i].pop();
	}	
	return 0;
}
