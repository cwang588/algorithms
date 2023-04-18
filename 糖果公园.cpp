#include<bits/stdc++.h>
using namespace std;
int a[150005];
struct xw
{
	int l,r,t,lw,rw,id,ans;
}q[150005];
int xgpos[150005],xgto[150005];
int cnt,now;
bool cmp(xw a,xw b)
{
	if(a.lw!=b.lw)return a.lw<b.lw;
	if(a.rw!=b.rw)return a.rw<b.rw;
	return a.t<b.t;
}
int num[1000005],col[150005];
//void doit(int poss)
//{
//	swap(col[xg[poss].pos],xg[poss].to);
//}
bool cmp1(xw a,xw b)
{
	return a.id<b.id;
}
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
int main()
{
	int n,m,k; 
	n=read();
	m=read();
	for(register int i=1;i<=n;++i)col[i]=read();
	for(register int i=1;i<=m;++i)
	{
		char c;
		cin>>c;
		int x,y;
		x=read();
		y=read();
		if(c=='Q')
		{
			++cnt;
			q[cnt].l=x;
			q[cnt].r=y;
			q[cnt].t=now;
		}
		else
		{
			++now;
			xgpos[now]=x;
			xgto[now]=y;
		}
	}
	int base=pow(n,2.0/3.0);
	for(register int i=1;i<=cnt;++i)
	{
		q[i].lw=q[i].l/base;
		q[i].rw=q[i].r/base;
		q[i].id=i;
	}
	sort(q+1,q+1+cnt,cmp);
	int l=0,r=0,t=0,ansnow=0;
	for(register int i=1;i<=cnt;++i)
	{
//		if(q[i-1].t<q[i].t)
//			for(int j=q[i-1].t+1;j<=q[i].t;++j)
//			{
//				if(xg[j].pos<=q[i-1].r&&xg[j].pos>=q[i-1].l)
//				{ 
//					if(!num[col[xg[j].pos]])++ansnow;
//					--num[col[xg[j].pos]];
//					if(num[xg[j].to]==1)--ansnow;	
//					++num[xg[j].to];			
//				}
//				doit(j);
//			}
//		else
//			for(int j=q[i-1].t;j>q[i].t;--j)
//			{
//				if(xg[j].pos<=q[i-1].r&&xg[j].pos>=q[i-1].l)
//				{ 
//					if(num[col[xg[j].pos]]==1)--ansnow;
//					--num[col[xg[j].pos]];
//					if(!num[xg[j].to])++ansnow;
//					++num[xg[j].to];				
//				}				
//				doit(j);
//			}
		while(t<q[i].t)
		{
			++t;
			if(xgpos[t]>=l&&xgpos[t]<=r)
			{
				if(num[col[xgpos[t]]]==1)--ansnow;
				--num[col[xgpos[t]]];
				if(num[xgto[t]]==0)++ansnow;
				++num[xgto[t]];
			}
			int tt=xgto[t];
			xgto[t]=col[xgpos[t]];
			col[xgpos[t]]=tt;
		}
		while(t>q[i].t)
		{
			if(xgpos[t]>=l&&xgpos[t]<=r)
			{
				if(num[col[xgpos[t]]]==1)--ansnow;
				--num[col[xgpos[t]]];
				if(num[xgto[t]]==0)++ansnow;
				++num[xgto[t]];
			}
			int tt=xgto[t];
			xgto[t]=col[xgpos[t]];
			col[xgpos[t]]=tt;
			--t;
		}
		while(r<q[i].r)
		{
			++r;
			if(num[col[r]]==0)++ansnow;
			++num[col[r]];
		}
		while(l>q[i].l)
		{
			--l;
			if(num[col[l]]==0)++ansnow;
			++num[col[l]];			
		}
		while(l<q[i].l)
		{
			--num[col[l]];
			if(num[col[l]]==0)--ansnow;
			++l;
		}
		while(r>q[i].r)
		{
			--num[col[r]];
			if(num[col[r]]==0)--ansnow;
			--r;			
		}		
		q[i].ans=ansnow;
	}
	sort(q+1,q+1+cnt,cmp1);
	for(register int i=1;i<=cnt;++i)printf("%d\n",q[i].ans);
	return 0;
}
