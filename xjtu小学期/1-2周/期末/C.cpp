#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+m,cmp);
	int l=0,r=1000000000;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		int tot=0;
		for(int i=1;i<=n;++i)
			tot+=a[i]/mid;
		if(tot>=n)
			l=mid;
		else
			r=mid;
	}
	int ans=r;
	int tott=0;
	for(int i=1;i<=n;++i)
		tott+=a[i]/ans;
	if(tott>=n)
		printf("%d",ans);
	else
		printf("%d",ans-1);
	return 0;
}
