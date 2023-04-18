#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int a[300005],n,m;
int f[830005][25];
int l[300005],r[300005],ll[300005],rr[300005];
vector<int>pos[300005];
int Min[300005*4],Max[300005*4];
inline int read() 
{
    char ch=getchar();
	int x=0,f=1;
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    } 
	while('0'<=ch&&ch<='9') 
	{
        x=x*10+ch-'0';
        ch=getchar();
    } 
	return x*f;
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		Min[rt]=n;
		Max[rt]=1;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	Min[rt]=n;
	Max[rt]=1;
}
void modify1(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(nowl<=l&&r<=nowr)
	{
		Min[rt]=min(k,Min[rt]);
		return;
	}
	int m=(l+r)>>1;
	Min[rt<<1]=min(Min[rt],Min[rt<<1]);
	Min[rt<<1|1]=min(Min[rt],Min[rt<<1|1]);
	if(nowl<=m)modify1(lson,nowl,nowr,k);
	if(nowr>m)modify1(rson,nowl,nowr,k);
}
void modify2(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(nowl<=l&&r<=nowr)
	{
		Max[rt]=max(k,Max[rt]);
		return;
	}
	int m=(l+r)>>1;
	Max[rt<<1]=max(Max[rt],Max[rt<<1]);
	Max[rt<<1|1]=max(Max[rt],Max[rt<<1|1]);
	if(nowl<=m)modify2(lson,nowl,nowr,k);
	if(nowr>m)modify2(rson,nowl,nowr,k);
}
void push_col(int l,int r,int rt)
{
	if(l==r)
	{
		ll[l]=Max[rt];
		rr[l]=Min[rt];
		return;
	}
	int m=(l+r)>>1;
	Max[rt<<1]=max(Max[rt],Max[rt<<1]);
	Max[rt<<1|1]=max(Max[rt],Max[rt<<1|1]);
	Min[rt<<1]=min(Min[rt],Min[rt<<1]);
	Min[rt<<1|1]=min(Min[rt],Min[rt<<1|1]);
	push_col(lson);
	push_col(rson);
}
int queryl(int now)
{
	int tmpl=0,tmpr=now;
	while(tmpl<tmpr-1)
	{
		int m=(tmpl+tmpr)>>1;
		int k=log2(now-m);
		if(max(f[m][k],f[now-(1<<k)][k])<a[now])tmpr=m;
		else tmpl=m;
	}
	return tmpr;
}
int queryr(int now)
{
	int tmpl=now,tmpr=n+1;
	while(tmpl<tmpr-1)
	{
		int m=(tmpl+tmpr)>>1;
		int k=log2(m-now);
		if(max(f[now+1][k],f[m-(1<<k)+1][k])<a[now])tmpl=m;
		else tmpr=m;
	}
	return tmpl;
}
int main()
{
	int t;
	t=read();
	while(t--)
	{
		int k;
		n=read(),k=read();
		build(1,n,1);
		for(int i=1;i<=n;++i)a[i]=read(),f[i][0]=a[i],pos[i].clear(),pos[i].push_back(0);
		for(int j=1;j<=19;++j)
			for(int i=1;i+(1<<j)<=n+1;++i)
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		for(int i=1;i<=n;++i)
		{
			pos[a[i]].push_back(i);
			int now=pos[a[i]].size();
			if(now>2)modify1(1,n,1,pos[a[i]][now-3]+1,pos[a[i]][now-2],pos[a[i]][now-1]-1);
		}
		for(int i=1;i<=n;++i)pos[i].clear(),pos[i].push_back(n+1);
		for(int i=n;i>=1;--i)
		{
			pos[a[i]].push_back(i);
			int now=pos[a[i]].size();
			if(now>2)modify2(1,n,1,pos[a[i]][now-2],pos[a[i]][now-3]-1,pos[a[i]][now-1]+1);
		}
		push_col(1,n,1);
		for(int i=1;i<=n;++i)
		{
			l[i]=queryl(i);
			r[i]=queryr(i);
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
            if(i-l[i]+1<=r[i]-i+1)
			{
                for(int j=l[i];j<=i;j++)
				{
                    if(rr[j]<i)continue;
                    int rrr=min(rr[j],r[i]);
                    int nn=i-j+1; 
                    if(max(1,a[i]-k)<=nn)ans+=rrr-i+1;
                    else ans+=max(0,rrr-a[i]+k-j+2);
                }
            }
            else
			{
                for (int j=i;j<=r[i];j++)
				{
                    if (ll[j]>i) continue;
                    int lll=max(ll[j],l[i]);
                    int mm=j-i+1;
                    if(max(1,a[i]-k)<=mm) ans+=i-lll+1;
                    else ans+=max(0,j+1-a[i]+k-lll+1);
                }
            }
        }
		printf("%lld\n",ans);
		for(int j=1;j<=19;++j)
			for(int i=1;i+(1<<j)<=n+1;++i)
				f[i][j]=0;
	}
	return 0;
}
