//kruskalÖØ¹¹Ê÷ 
#include<bits/stdc++.h>
using namespace std;
struct bian
{
	int x,y,z;
}E[100005];
struct edge
{
	int from,to,nxt;
}e[200005];
int cnt,Head[100005],tot,rt,sum[200005];
int fa[100005];
struct query
{
	int from,to,nxt;
}q[1000005];
int qhead[500005],qfa[500005],ans[500005];
//void add(int x,int y)
//{
//	++cnt;
//	e[cnt].from=x;
//	e[cnt].to=y;
//	e[cnt].nxt=Head[x];	
//	Head[x]=cnt;
//}
int qfather(int x)
{
	if(qfa[x]==x)
		return x;
	qfa[x]=qfather(qfa[x]);
	return qfa[x];
}
void qMerge(int r1,int r2)
{
	qfa[r2]=r1;
}
int qcnt;
void qadd(int x,int y)
{
	++qcnt;
	q[qcnt].from=x;
	q[qcnt].to=y;
	q[qcnt].nxt=qhead[x];	
	qhead[x]=qcnt;
}
bool usd[500005];
void dfs(int now,int pre)
{
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to!=pre)
		{
			dfs(e[i].to,now);
			qMerge(now,e[i].to);
			usd[e[i].to]=true;
		}
	}
	for(int i=qhead[now];i;i=q[i].nxt)
	{
		if(usd[q[i].to])
			ans[(i+1)/2]=qfather(q[i].to);
	}
}
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void Merge(int x,int y,int z)
{
	++tot;
	add(x,tot);
	add(y,tot);
	add(tot,x);
	add(tot,y);
	sum[tot]=z;
	fa[x]=fa[y]=rt=tot;
}
bool cmp(bian a,bian b)
{
	return a.z>b.z;
}
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].z);		
	for(int i=m+1;i<=m+1+n;++i)
	{
		E[i].x=0;
		E[i].y=i;
		E[i].z=-1;
	}
	sort(E+1,E+1+m,cmp);
	for(int i=1;i<=2*n;++i)fa[i]=i,qfa[i]=i;
	tot=n;
	int num=0;
	for(int i=1;i<=m+n;++i)
	{
		int r1=getfa(E[i].x),r2=getfa(E[i].y);
		if(r1!=r2)
		{
			++num;
			Merge(r1,r2,E[i].z);
//			add(E[i].x,E[i].y);
//			add(E[i].y,E[i].x);
		}
		if(num==n)break;
	}
	int qnum;
	scanf("%d",&qnum);
	for(int i=1;i<=qnum;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		qadd(x,y); 
		qadd(y,x); 
	}
	dfs(rt,3*n);
	for(int i=1;i<=qnum;++i)
	{
		if(!ans[i])printf("-1\n");
		else printf("%d\n",sum[ans[i]]);
	}
	return 0; 
}
