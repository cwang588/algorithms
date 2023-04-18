#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
vector<int>v;
int m;
int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
struct weapon
{
	int atk;
	long long value;
}w[200005];
bool cmp1(weapon x,weapon y)
{
	return x.atk<y.atk;
}
struct armor
{
	int dfn;
	long long value;
}a[200005];
struct monster
{
	int atk,dfn;
	long long value;
}mo[200005];
bool cmp2(monster x,monster y)
{
	return x.dfn<y.dfn;
}
long long sum[400055*8],Max[400055*8],col[400005*8];
bool usd[400005];
void push_col(int l,int r,int rt)
{
	int m=(l+r)>>1;
	sum[rt<<1]+=(m-l+1)*col[rt];
	sum[rt<<1|1]+=(r-m)*col[rt];
	col[rt<<1]+=col[rt];
	col[rt<<1|1]+=col[rt];
	Max[rt<<1]+=col[rt];
	Max[rt<<1|1]+=col[rt];
	col[rt]=0;
}
void modify(int l,int r,int rt,int nowl,int nowr,long long k)
{
	if(l>=nowl&&r<=nowr)
	{
		col[rt]+=k;
		sum[rt]+=(r-l+1)*k;
		Max[rt]+=k;
		return;
	}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(m>=nowl)modify(lson,nowl,nowr,k);
	if(m<nowr)modify(rson,nowl,nowr,k);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
long long query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return Max[rt];
	push_col(l,r,rt);
	int m=(l+r)>>1;
	long long re=-21474836477;
	if(m>=nowl)re=max(re,query(lson,nowl,nowr));
	if(m<nowr)re=max(re,query(rson,nowl,nowr));
	return re;
}
void build(int l,int r,int rt,int pos,long long k)
{
	if(l==r)
	{
		sum[rt]=Max[rt]=max(Max[rt],k);
		return;
	}
	int m=(l+r)>>1;
	if(m>=pos)build(lson,pos,k);
	else build(rson,pos,k);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
int main()
{
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	long long Min1=21474836477,Min2=21474836477;
	for(int i=1;i<=n;++i)scanf("%d%lld",&w[i].atk,&w[i].value),Min1=min(Min1,w[i].value);
	for(int i=1;i<=m;++i)scanf("%d%lld",&a[i].dfn,&a[i].value),Min2=min(Min2,a[i].value),v.push_back(a[i].dfn);
	for(int i=1;i<=p;++i)scanf("%d%d%lld",&mo[i].dfn,&mo[i].atk,&mo[i].value),v.push_back(mo[i].atk);
	sort(w+1,w+1+n,cmp1);
	sort(mo+1,mo+1+p,cmp2);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int tot=v.size();
	for(int i=1;i<=tot*16;++i)Max[i]=-21474836477;
	for(int i=1;i<=m;++i)
	{
		int now=getid(a[i].dfn);
		build(1,tot,1,now,-a[i].value);
		usd[now]=true;
	}
	for(int i=1;i<=tot;++i)
		if(!usd[i])
			build(1,tot,1,i,-21474836477);
	int index=0;
	long long ans=-Min1-Min2;
	for(int i=1;i<=n;++i)
	{
		while(mo[index+1].dfn<w[i].atk&&index<p)
		{
			++index;
			int tmp=getid(mo[index].atk);
			modify(1,tot,1,tmp+1,tot,mo[index].value);
		}
		ans=max(ans,query(1,tot,1,1,tot)-w[i].value);
	}
	printf("%lld\n",ans);
	return 0;
}
