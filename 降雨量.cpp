#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct nian
{
	int year,data,id;
}d[50005];
struct query
{
	int l,r,lw,rw,id,ans;
}q[10005];
bool cmplsh1(nian x,nian y)
{
	return x.data<y.data;
}
bool cmplsh2(nian x,nian y)
{
	return x.year<y.year;
}
bool cmp1(query x,query y)
{
	if(x.lw!=y.rw)
		return x.lw<y.lw;
	return x.rw<y.rw;
}
bool cmp2(query x,query y)
{
	return x.id<y.id;
}
int cnt[50005];
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&d[i].year,&d[i].data);
	sort(d+1,d+1+n,cmplsh1);
	int now=0;
	for(int i=1;i<=n;++i)
	{
		if(d[i].data>d[i-1].data)
			d[i].id=++now;
		else
			d[i].id=now;
	}
	sort(d+1,d+1+n,cmplsh2);
	int base=(int)sqrt((double)n);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].lw=q[i].l/base;
		q[i].rw=q[i].r/base;
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp1);
	int L=0,R=0,Max=0;
	for(int i=1;i<=n;++i)
	{
		if(d[i].year>=q[1].l&&d[i-1].year<q[1].l)
			L=i;
		if(d[i].year<=q[1].r&&d[i+1].year>q[1].r)
			R=i;	
	}
	if(!R)
		R=n+1;
	for(int i=L;i<=R;++i)
	{
		++cnt[d[i].id];
		if(Max<d[i].id&&d[i].year!=q[1].l)
			Max=d[i].id;
	}
	if(R==n+1)
		q[1].ans=3;
	else
	{
		if(Max>d[R].id)
			q[1].ans=1;
		else
		{
			if(cnt[Max]>1)
				q[1].ans=1;
			else
			{
				if(d[R].year-d[L].year==R-L&&d[R].id<=d[L].id)
					q[1].ans=2;
				else 
					q[1].ans=3;
			}
		}
	}
	for(int i=2;i<=m;++i)
	{
		if(d[L].year>q[i].l)
		{
			int j;
			for(j=L-1;d[j].year>q[i].l;--j)
			{
				++cnt[d[j].id];
				if(Max<d[j].id)
					Max=d[j].id;
			}
			L=j;
		}
		if(d[R].year<q[i].r)
		{
			int j;
			for(j=R+1;d[j].year<=q[i].r;++j)
			{
				++cnt[d[j].id];
				if(Max<d[j].id)
					Max=d[j].id;
			}	
			R=j;
		}
		if(d[L].year<q[i].l)
		{
			int j;
			for(j=L;d[j].year<q[i].l;++j)
			{
				--cnt[d[j].id];
				if(!cnt[d[j].id]&&d[j].id==Max)
				{
					for(int k=Max-1;;--k)
						if(cnt[k])
						{
							Max=k;
							break;
						}
				}
			}
			L=j;
		}
		if(q[i].r<d[R].year)
		{
			int j;
			for(j=R;d[j].year>q[i].r;--j)
			{
				--cnt[d[j].id];
				if(!cnt[d[j].id]&&d[j].id==Max)
				{
					for(int k=Max-1;;--k)
						if(cnt[k])
						{
							Max=k;
							break;
						}
				}
			}
			R=j;
		}	
		if(Max==d[L].id)
		{
			for(int k=Max-1;;--k)
				if(cnt[k])
				{
						Max=k;
						break;
				}
		}
		if(Max>d[R].id)
			q[i].ans=1;
		else
		{
			if(cnt[Max]>1)
				q[i].ans=1;
			else
			{
				if(d[R].year-d[L].year==R-L&&d[R].id<=d[L].id)
					q[i].ans=2;
				else 
					q[i].ans=3;
			}
		}	
		Max=max(Max,d[L].id);
	}
	sort(q+1,q+1+m,cmp2);
	for(int i=1;i<=m;++i)
	{
		if(q[i].ans==1)
			printf("false\n");
		else if(q[i].ans==2)
			printf("true\n");
		else
			printf("maybe\n");
	}
	return 0;
}
