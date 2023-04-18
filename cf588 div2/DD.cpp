#include<cstdio>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
bool aa[7005][7005];
long long t[7025];
int a[30005],tl[30005],nx[30005];
int b[7025];
int cnt[7025];
int Max[30005],Maxid[30005];
void update(int rt)
{
	if(Max[rt<<1]>Max[rt<<1|1])
	{
		Max[rt]=Max[rt<<1];
		Maxid[rt]=Maxid[rt<<1];
	}
	else
	{
		Max[rt]=Max[rt<<1|1];
		Maxid[rt]=Maxid[rt<<1|1];
	}
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		Max[rt]=cnt[l];
		Maxid[rt]=l;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(rt);
}
void modify(int l,int r,int rt,int nowl,int opt)
{
if(l==r&&l==nowl)
{
if(opt) Max[rt]--;
else Max[rt]=0;
return;
}
int m=(l+r)>>1;
if(m>=nowl) modify(lson,nowl,opt);
if(m<nowl) modify(rson,nowl,opt);
update(rt);
}
bool del[7025];
int main()
{
	int n,ln=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) tl[i]=++ln;
	for(int i=1;i<=n;i++) scanf("%lld",&t[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
	if(i==j) continue;
	if((t[i]^t[j])&t[i])
	{
		cnt[i]++;
		aa[i][j]=true;
	//	printf("%d->%d\n",j,i);
	}
	}
	int pos;
	long long ans=0;
	build(1,n,1);
	for(int i=1;i<=n;i++)
	{
		int p=Maxid[1],Maxx=Max[1];
		if(Maxx<n-i)
		{
			pos=i;
			break;
		}
		else
		{
			for(int j=1;j<=n;++j)
				if(aa[p][j]&&!del[j])
					modify(1,n,1,j,1);
			modify(1,n,1,p,0);
			del[p]=true;
		}
	}
	int anss=0;
	for(int i=1;i<=n;i++) if(!del[i]) ans+=b[i],anss++;
	if(anss!=1) printf("%lld\n",ans);
	else printf("0");
}
