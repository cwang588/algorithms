#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

struct Node
{
	int l,r;
};
Node e[500005];
int fa[1000005];
set <int> st;
bool cmp(Node x,Node y)
{
	return x.l<y.l;
}
int pos(int x)
{
	if(fa[x]!=x) return fa[x]=pos(fa[x]);
	return x;
}
void combine(int x,int y)
{
	if((x=pos(x))==(y=pos(y))) return;
	else fa[y]=pos(x);
	return;
}
bool check(int x,int y)
{
	if(pos(x)==pos(y)) return true;
	else return false;
}
int ans;
int nmsl()
{
	return 0;
}
int two()
{
	return nmsl();
}
int one()
{
	return two();
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&e[i].l,&e[i].r);
	for(int i=1;i<=n*2;i++) fa[i]=i;
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		set<int>::iterator it=st.lower_bound(e[i].l);
		for(;it!=st.end()&&*it<e[i].r;it++)
		{
			if(check(*it,e[i].r)) return !printf("NO\n");
			combine(*it,e[i].r);
			ans++;
		}
		st.insert(e[i].r);
	}
	if(ans<n-1) return!printf("NO\n");
	printf("YES\n");
	return one();
}

