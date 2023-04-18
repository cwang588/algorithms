#include<bits/stdc++.h>
#define maxn 100005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
long long sum[maxn*4];
int num[maxn];
int n,m;
void build(int l,int r,int rt)
{
	if(l==r)
	{
		sum[rt]=(long long)l;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(sum,0,sizeof(sum));
		memset(num,0,sizeof(num));
		scanf("%d%d",&n,&m);
		build(1,n,1);
		for(int i=1;i<=n;++i)num[i]=i;
		for(int i=1;i<=m;++i)
		{
			int pos,x,y;
			scanf("%d%d%d",&pos,&x,&y);
			if(pos==1)
			{
				if(num[x]==x)
			}			
		}
	}
	return 0;
}
