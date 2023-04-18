#include<bits/stdc++.h>
using namespace std;
int a[1008];
double b[1008];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)
			cin>>b[i];	
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n);
		double ans=0;
		for(int i=1;i<=n;++i)
			ans+=(double)a[i]*b[i];
		printf("%.3lf\n",ans);
	} 
	return 0;
}
