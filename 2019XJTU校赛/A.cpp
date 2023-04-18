#include<bits/stdc++.h>
using namespace std;
const int N=200005;
struct node
{
	int num,son[2];
}T[32*N];
int cnt,x[45];
long long mi[45];
void init()
{
	mi[0]=1;
	for(int i=1;i<=40;++i)mi[i]=2*mi[i-1];
}
void insert(int xx)
{
	int cur=0,now=0;
	for(int i=0;i<=31;++i)
	{
		int t=((1<<i)&xx)?1:0;
		int pos=T[cur].son[t];
		if(!pos)pos=T[cur].son[t]=++cnt;
		cur=pos;
		++T[cur].num;
		if(t)++x[now];
		++now;
	}
}
void modify(int now,int dep)
{
	if(!T[now].son[0]&&!T[now].son[1])return;
	if(T[now].son[1])modify(T[now].son[1],dep+1);
	if(T[now].son[1])x[dep]-=T[T[now].son[1]].num;
	if(T[now].son[0])x[dep]+=T[T[now].son[0]].num;
	swap(T[now].son[0],T[now].son[1]);
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		if(t==2)
		{
			int x;
			scanf("%d",&x);
			insert(x);
		}
		else modify(0,0);
		long long ans=0;
		for(int j=0;j<=40;++j)
			if(x[j]%2)
				ans+=mi[j];
		printf("%lld\n",ans);
	}
	return 0;
} 
