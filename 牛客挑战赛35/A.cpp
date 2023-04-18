#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
bool cmp(long long x,long long y)
{
	return x>y;
} 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n,cmp);
	long long ans=0;
	for(int i=1;i<=n;++i)ans+=max(1ll*0,b[i]-a[i]);
	cout<<ans<<endl;
	return 0;
}
