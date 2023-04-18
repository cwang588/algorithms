#include<bits/stdc++.h>
using namespace std;
struct modify
{
	int pos,num;
}p[2005];
bool cmp(modify a,modify b)
{
	return a.pos<b.pos;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int Case=1;Case<=t;++Case)
	{
		for(int i=1;i<=2000;++i)p[i].num=p[i].pos=0;
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			p[2*i-1].pos=l;
			p[2*i-1].num=1;
			p[2*i].pos=r+1;
			p[2*i].num=-1;
		} 
		sort(p+1,p+2*m+1,cmp);
		int tot=0,ans=0;
		for(int i=1;i<=2*m;++i)
		{
			tot+=p[i].num;
			if(tot%2)ans+=p[i+1].pos-p[i].pos;
		}
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}
