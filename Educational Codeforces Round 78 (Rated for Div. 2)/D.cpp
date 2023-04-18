#include<bits/stdc++.h>
using namespace std;
struct se
{
	int l,r;
	bool operator < (const se &b)const
	{
		if((l>b.l&&r<b.r)||(r>b.r)||(l<b.l))return true;
		return false;
	} 
}m[500005];
int fa[1000005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void hb(int x,int y)
{
	fa[x]=y;
}
set<se>s;
int main()
{
	int n;
	scanf("%d",&n);	
	for(int i=1;i<=n;++i)
	{
		cin>>m[i].l>>m[i].r;
		s.insert(m[i]);
	}
	for(int i=1;i<=2*n;++i)fa[i]=i;
	int tot=0;
	for(int i=1;i<=n;++i)
	{
		set<se>::iterator it=s.lower_bound(m[i]);
		if(*it<m[i]||m[i]<*it)continue;
		set<se>::iterator it1=++it,it2=(--it)--;
		while(!(*it1<m[i])&&!(m[i]<*it1))
		{
			int r1=
		}
	}
	return 0;
}
