#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,y,z;
	bool operator <(const point& b) const
    {
    	if(x!=b.x)return x<b.x;
    	if(y!=b.y)return y<b.y;
        return z<b.z;
    };
}p[50005];
bool cmp(point a,point b)
{
	if(a.x!=b.x)return a.x<b.x;
	if(a.y!=b.y)return a.y<b.y;
	return a.z<b.z;
}
set<pair<int,int> >s[50005];
map<point,int>m;
int xx[50005];
bool usd[50005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z),m[p[i]]=i;
	sort(p+1,p+1+n,cmp);
	p[0].x=-2147483647;
	int nowx=0,tot=0;
	for(int i=1;i<=n;++i)
	{
		if(p[i].x>p[i-1].x)++tot;
		xx[tot]=p[i].x;
		s[tot].insert(make_pair(p[i].y,p[i].z));
	}
	int now=1;
	point aa,bb;
	set<pair<int,int> >::iterator it,itt;
	pair<int,int>t,tt;
	for(int i=1;i<n/2;++i)
	{
		it=s[now].begin();
		t=*it;
		aa.x=xx[now];
		aa.y=t.first;
		aa.z=t.second;
		s[now].erase(it);
		if(s[now].empty())++now;
		itt=s[now].lower_bound(t);
		tt=*itt;
		bb.x=xx[now];
		bb.y=tt.first;
		bb.z=tt.second;
		s[now].erase(itt);
		if(s[now].empty())++now;
		printf("%d %d\n",m[aa],m[bb]);
		usd[m[aa]]=usd[m[bb]]=true;
	}
	for(int i=1;i<=n;++i)
		if(!usd[i])printf("%d ",i);
	for(int i=1;i<=tot;++i)s[i].clear();
	m.clear();
	return 0;
}
