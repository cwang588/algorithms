#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int fa[100005],value[100005];
int getfa(int x)
{
	int t=fa[x];
	if(fa[x]!=x)
	{
		fa[x]=getfa(fa[x]);
		value[x]^=value[t];
	}
	return fa[x];
}
void Merge(int x,int y,int z)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
	value[r1]=value[y]^z^value[x];
}
vector<int>v;
int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
struct query
{
	int l,r;
	bool even;
}q[100005];
int main()
{
//	ios::sync_with_stdio(false);
	int tot,n;
	cin>>tot>>n;
	for(int i=1;i<=n;++i)
	{
		string s;
		cin>>q[i].l>>q[i].r>>s;
		if(s=="even")q[i].even=true;
		else q[i].even=false;
		--q[i].l;
		v.push_back(q[i].l);
		v.push_back(q[i].r);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=v.size();++i)fa[i]=i;
	for(int i=1;i<=n;++i)
	{
		int nowl=getid(q[i].l),nowr=getid(q[i].r);
		int r1=getfa(nowl),r2=getfa(nowr);
		if(r1==r2)
		{
			bool judge=((value[nowr]^value[nowl])==0);
			if(judge!=q[i].even)return !printf("%d\n",i-1);
		}
		else Merge(nowl,nowr,q[i].even?0:1);
	}
	printf("%d\n",n);
	return 0;
}
