#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int n,m;
long long L;
bool check(int x)
{
	int now=0,cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]-now<x)++cnt;
		else 
		{
			if(L-a[i]<x)++cnt;
			now=a[i];
		}
		if(cnt>m)return false;
	}
	return cnt<=m;
}
int main()
{
	ios::sync_with_stdio(false); 
	cin>>L>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	int l=1,r=L;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	if(check(r))printf("%d\n",r);
	else printf("%d\n",l);
	return 0;
} 
