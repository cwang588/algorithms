#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005],c[1005],d[1005];
long long sumd[2005],sumc[2005];
int num1,num2,num3,num4;
int main()
{
	scanf("%d",&num1);
	for(int i=1;i<=num1;++i)
		scanf("%d",&a[i]);
	scanf("%d",&num2);
	for(int i=1;i<=num2;++i)
		scanf("%d",&b[i]);
	scanf("%d",&num3);
	int Maxc=0,Maxd=0;
	for(int i=1;i<=num3;++i)
	{
		scanf("%d",&c[i]);
		++sumc[c[i]];
	//	Maxc=max(Maxc,c[i]);
	}
	scanf("%d",&num4);
	for(int i=1;i<=num4;++i)
	{
		scanf("%d",&d[i]);	
		++sumd[d[i]];
	//	Maxd=max(Maxd,d[i]);
	}
	for(int i=1;i<=2000;++i)
		sumc[i]+=sumc[i-1];
	for(int i=1;i<=2000;++i)
		sumd[i]+=sumd[i-1];
	long long ans=0;
	for(int i=1;i<=num1;++i)
		for(int j=1;j<=num2;++j)
		{
			int t1=max(a[i],b[j]),t2=min(a[i],b[j]);
			ans+=sumc[t2]*sumd[t1]+sumc[t1]*sumd[t2]-sumc[t2]*sumd[t2];
		}
//	for(int i=1;i<=num3;++i)
//		for(int j=1;j<=num4;++j)
//			++tong[max(c[i],d[j])][2001-min(c[i],d[j])];
//	for(int i=1;i<=2000;++i)
//		for(int j=1;j<=2000;++j)
//			sum[i][j]=tong[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
//	long long ans=0;
//	for(int i=1;i<=num1;++i)
//		for(int j=1;j<=num2;++j)
//		{
//			int t1=max(a[num1],b[num2]),t2=min(a[num1],b[num2]);
//			ans+=sum[t1][t2];
//		}	
	printf("%lld",ans);
	return 0;
}
