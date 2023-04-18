#include<bits/stdc++.h>
using namespace std;
struct dian
{
	int tpe;
	long long x;
}d[200005];
struct jg
{
	int l,r;
}h[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		long long t;
		char c;
		cin>>t>>c;
		d[i].x=t;
		if(c=='N')
			d[i].tpe=0;
		else if(c=='S')
			d[i].tpe=1;
		else
			d[i].tpe=2;
	}
	int now=1,tot=0;
	while(now<n)
	{
		if(!d[now].tpe&&d[now+1].tpe)
			h[++tot].l=now;
		if(d[now].tpe&&!d[now+1].tpe&&tot)
			h[tot].r=now+1;
		++now;
	}
	if(!tot||(tot==1&&!h[tot].r))
	{
		int ss=999999,se=0,fs=999999,fe=0;
		for(int i=1;i<=n;++i)
		{
			if(d[i].tpe!=2)
			{
				ss=min(ss,i);
				se=max(se,i);
			}
			if(d[i].tpe!=1)
			{
				fs=min(ss,i);
				fe=max(se,i);
			}
		}
		cout<<d[fe].x+d[se].x-d[fs].x-d[ss].x;
	}
	long long ans=0;
	for(int i=1;i<=tot;++i)
	{
		if(!h[i].r)
			continue;
		int l1,l2;
		long long m1,m2;
		l1=l2=h[i].l;
		m1=m2=0;
		for(int j=h[i].l+1;j<h[i].r;++j)
		{
			if(d[j].tpe==1)
			{
				m1=max(m1,d[j].x-d[l1].x);
				l1=j;
			}
			if(d[j].tpe==2)
			{
				m1=max(m2,d[j].x-d[l2].x);
				l2=j;
			}			
		}
		m1=max(m1,d[h[i].r].x-d[l1].x);
		m2=max(m2,d[h[i].r].x-d[l2].x);
		ans+=3*(d[h[i].r].x-d[h[i].l].x)-max(m1+m2,d[h[i].r].x-d[h[i].l].x);
	}
	for(int i=1;i<=h[1].l;++i)
	{
		if(d[i].tpe==1)
		{
			ans+=d[h[1].l].x-d[i].x;
			break;
		}
	}
	for(int i=1;i<=h[1].l;++i)
	{
		if(d[i].tpe==2)
		{
			ans+=d[h[1].l].x-d[i].x;
			break;
		}
	}
	int ttt;
	for(int i=n;i>=1;--i)
		if(!d[i].tpe)
		{
			ttt=i;
			break;
		}
	for(int i=n;i>=ttt;--i)
	{
		if(d[i].tpe==1)
		{
			ans+=d[i].x-d[ttt].x;
			break;
		}
	}
	for(int i=n;i>=ttt;--i)
	{
		if(d[i].tpe==2)
		{
			ans+=d[i].x-d[ttt].x;
			break;
		}
	}
	cout<<ans;
	return 0;
}
