#include<bits/stdc++.h>
using namespace std;
int power[10005],fa[10005],value[10005];
struct query
{
	bool type;
	int x,y,ans;
}q[50005];
map<pair<int,int>,bool>mm;
struct TD
{
	int x,y;
}td[20005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
	if(power[value[r1]]>power[value[r2]]||(power[value[r1]]==power[value[r2]]&&value[r1]<value[r2]))value[r2]=value[r1];
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	int cnt=1;
	while(cin>>n)
	{
		if(cnt>1)cout<<endl;
		++cnt;
		for(int i=0;i<n;++i)cin>>power[i];
		int m,k;
		cin>>m;
		for(int i=1;i<=m;++i)
		{
			cin>>td[i].x>>td[i].y;
			if(td[i].x>td[i].y)swap(td[i].x,td[i].y);	
		}
		for(int i=0;i<=n;++i)fa[i]=value[i]=i;
		cin>>k;
		for(int i=1;i<=k;++i)
		{
			string s;
			cin>>s;
			if(s=="destroy")
			{
				q[i].type=false;
				cin>>q[i].x>>q[i].y;
				if(q[i].x>q[i].y)swap(q[i].x,q[i].y);
				mm[make_pair(q[i].x,q[i].y)]=true;
			}
			else
			{
				q[i].type=true;
				cin>>q[i].x;
			}
		}
		for(int i=1;i<=m;++i)
		{
			if(mm[make_pair(td[i].x,td[i].y)])continue;
			Merge(td[i].x,td[i].y);
		}
		for(int i=k;i>=1;--i)
		{
			if(q[i].type)
			{
				getfa(q[i].x);
				if(power[value[fa[q[i].x]]]>power[q[i].x])q[i].ans=value[fa[q[i].x]];
				else q[i].ans=-1;
			}
			else Merge(q[i].x,q[i].y);
		}
		for(int i=1;i<=k;++i)if(q[i].type)printf("%d\n",q[i].ans);
	//	printf("\n\n");
		mm.clear();
	}
	return 0;
}
