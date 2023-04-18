#include<bits/stdc++.h>
using namespace std;	
int a[5000005],b[5000005];
int main()
{
//	freopen("sb1.in","r",stdin);
//	freopen("sb1.out","w",stdout);
	int n,m,k; 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)
		scanf("%d",&b[i]);
	int now1=0,now2=0;
	while(now1+now2<=k)
	{
		if(a[now1]<=b[now2])
			++now1;
		else
			++now2;
	}
	printf("%d",min(a[now1],b[now2]));
	return 0;
}
