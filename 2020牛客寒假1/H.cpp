#include<bits/stdc++.h>
using namespace std;
int n,k;
int sum[200005];
bool check(int x)
{
	for(int i=1;i+x-1<=n;++i)
	{
		int j=i+x-1;
		int ze=sum[j]-sum[i-1];
		int num=min(ze,x-ze);
		if(num<=k)return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		char t;
		cin>>t;
		sum[i]=sum[i-1]+(t=='0'?1:0);
	}
	int l=1,r=n;
	while(l<r-1)
	{
		int m=(l+r)>>1;
		if(check(m))l=m;
		else r=m;
	}
	if(check(r))printf("%d\n",r);
	else printf("%d\n",l);
	return 0;
}
