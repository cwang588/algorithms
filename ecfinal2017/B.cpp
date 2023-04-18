#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<double,int> >q;
int a[200005],num[200005];
signed main()
{
	int t;
	scanf("%d",&t);
	for(int Case=1;Case<=t;++Case)
	{
		memset(a,0,sizeof(a));
		memset(num,0,sizeof(num));
		int n,m;double tot=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),tot+=1.0*a[i];	
		int re=m-n;
		for(int i=1;i<=n;++i)
		{
			num[i]=1;
			q.push(make_pair(0.5*(a[i]*a[i]),i));
		}
		while(re--)
		{
			int now=q.top().second;
			q.pop();
			++num[now];
			double aa=1.0*a[now],nn=1.0*num[now];
			q.push(make_pair(aa*aa/(nn*(nn+1.0)),now));
		}
		double ans=0.0,pj=1.0*tot/m;
		for(int i=1;i<=n;++i)
		{
			double aa=1.0*a[i],nn=1.0*num[i];
			ans+=(aa/nn-pj)*(aa/nn-pj)*nn;
		}
		printf("Case #%d: %.16lf\n",Case,ans/m);
	}
	return 0;
}
