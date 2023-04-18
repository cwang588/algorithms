#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005];
int ans[1000005];
int n;
void work()
{
	memset(b,0,sizeof(b));
	for(int i=1;i<n;++i)
	{
		if(a[i]<a[i+1])b[i]=0;
		else b[i]=1;
	}
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	printf(":");
	for(int i=1;i<n;++i)printf("%d ",b[i]);
	printf("\n");
	long long now=0;
	for(int i=1;i<n;++i)now=now*2+b[i];
	++ans[now];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)a[i]=i;
	work();
	while(next_permutation(a+1,a+1+n))work(); 
//	for(int i=0;i<pow(2,n-1);++i)printf("%d\n",ans[i]);
	return 0;
}
