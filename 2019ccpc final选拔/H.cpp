#include<bits/stdc++.h>
using namespace std;
set<int>s;
struct qj
{
	int a,b,c;
}q[100005];
int a[100005];
int sum1[100005],sum2[100005];
bool cmp(qj x,qj y)
{
	if(x.b==y.b)
	{
		if(x.a!=y.a)return x.a<y.a;
		return x.c<y.c;
	}
	return x.b<y.b;
}
int sum[100005],n;
int lowbit(int x)
{
	return x&(-x);
}
int query(int x)
{
	int re=0;
	while(x)
	{
		re+=sum[x];
		x-=lowbit(x);
	}
	return re;
}
void add(int x,int y)
{
	while(x<=n)
	{
		sum[x]+=y;
		x+=lowbit(x);
	}
}
int del[200005];
int main()
{
	int k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		add(i,a[i]);
		sum1[i]=sum1[i-1];
		sum2[i]=sum2[i-1];
		if(a[i]==1)++sum1[i];
		if(a[i]==-1)++sum2[i];
		if(a[i]==0)s.insert(i);
	}
	bool ky=true; 
	for(int i=1;i<=k;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(c>b-a+1-2*(sum2[b]-sum2[a-1]))ky=false;
		q[i].a=a;
		q[i].b=b;
		q[i].c=c;
	}
	if(!ky)return !printf("Impossible\n");
	sort(q+1,q+1+k,cmp);
	if(s.empty())
	{
		for(int i=1;i<=n;++i)printf("%d ",a[i]);
		return 0;
	}
	for(int i=1;i<=k;++i)
	{
		del[0]=0;
		set<int>::iterator it=s.upper_bound(q[i].b);
		--it;
		int now=*it;
		int he=query(q[i].b)-query(q[i].a-1);
		while(he<q[i].c)
		{
			if(!a[now])
			{
				++he;
				a[now]=1;
				add(now,1);
				del[++del[0]]=now;
				if(it==s.begin())break;
				--it;
				now=*it;
			}
		}
		for(int j=1;j<=del[0];++j)s.erase(del[i]);
	}
	for(int i=1;i<=n;++i)
		if(!a[i])a[i]=-1;
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}
