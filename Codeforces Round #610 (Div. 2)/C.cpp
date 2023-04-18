#include<bits/stdc++.h>
using namespace std;
long long a[200005],s[200005],sk[200005];
int main()
{
	ios::sync_with_stdio(false);
	int t; 
	cin>>t;
	while(t--)
	{
		int n,k;
		long long p;
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		memset(sk,0,sizeof(sk));
		cin>>n>>p>>k;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i)
		{
			s[i]=s[i-1]+a[i];
			if(i>=k)sk[i]=sk[i-k]+a[i];	
		}
		bool ky=false;
		for(int i=n;i>=1;--i)
		{
			long long tot=s[i%k]+sk[i];
			if(tot<=p)
			{
				ky=true;
				printf("%d\n",i);
				break;
			}
		}
		if(!ky)printf("0\n");
	}
	
	return 0;
	
}
