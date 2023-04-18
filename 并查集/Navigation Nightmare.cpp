#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int fa[100005],valuex[100005],valuey[100005];
int getfa(int x)
{
	if(fa[x]!=x)
	{
		int t=fa[x];
		fa[x]=getfa(fa[x]);
		valuex[x]+=valuex[t];
		valuey[x]+=valuey[t];
	}
	return fa[x];
}
void Merge(int x,int y,int vx,int vy)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
	valuex[r1]=valuex[y]+vx-valuex[x];
	valuey[r1]=valuey[y]+vy-valuey[x];
}
struct information
{
	int x,y,z;
	char t;
}infor[100005];
struct query
{
	int x,y,num,id,ans;
}q[100005];
bool cmp1(query a,query b)
{
	return a.num<b.num;
}
bool cmp2(query a,query b)
{
	return a.id<b.id;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)cin>>infor[i].x>>infor[i].y>>infor[i].z>>infor[i].t;
	cin>>k;
	for(int i=1;i<=k;++i)cin>>q[i].x>>q[i].y>>q[i].num,q[i].id=i;
	sort(q+1,q+1+k,cmp1);
	for(int i=1;i<=k;++i)
	{
		for(int j=q[i-1].num+1;j<=q[i].num;++j)
		{
			if(infor[j].t=='N')Merge(infor[j].x,infor[j].y,0,infor[j].z);
			else if(infor[j].t=='S')Merge(infor[j].x,infor[j].y,0,-infor[j].z);
			else if(infor[j].t=='W')Merge(infor[j].x,infor[j].y,infor[j].z,0);
			else Merge(infor[j].x,infor[j].y,-infor[j].z,0);
		}
		int r1=getfa(q[i].x),r2=getfa(q[i].y);
		if(r1!=r2)q[i].ans=-1;
		else q[i].ans=abs(valuex[q[i].x]-valuex[q[i].y])+abs(valuey[q[i].x]-valuey[q[i].y]);
	}
	sort(q+1,q+1+k,cmp2);
	for(int i=1;i<=k;++i)printf("%d\n",q[i].ans);
	return 0;
}
