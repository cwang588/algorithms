#include<cstdio>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
struct qujian
{
	int l,r;
}e[2000005];
bool cmp(qujian a,qujian b)
{
	return a.l<b.l;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d",&e[i].l,&e[i].r);
	sort(e+1,e+1+m,cmp);
	int rr=0,num=0,now=0;
	while(rr<n)
	{
		int tep=rr;
		bool you=false;
		for(int i=now;i<=m;++i)
		{
			if(e[i].l>tep+1)
				break;
			you=true;
			rr=max(rr,e[i].r);
			now=i+1;
		}
		if(!you)
		{
			printf("-1");
			return 0;
		}
		++num;
	}
	printf("%d",num);
	return 0;
}
