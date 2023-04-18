#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main()
{
	int n;
	scanf("%d",&n);
	long long tot=0;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),tot+=a[i]-a[1]-i+1;
	long long tmp=a[1];
	for(int i=1;i<=n;++i)a[i]=tmp+i-1+tot/n; 
	for(int i=1;i<=tot%n;++i)++a[i];
	for(int i=1;i<=n;++i)printf("%lld ",a[i]);
	return 0;
}
