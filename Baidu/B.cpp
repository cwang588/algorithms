#include<bits/stdc++.h>
using namespace std;
char a[200005],b[200005];
int suma[200005],sumb[200005],sum[200005];
int main()
{
//	ios::sync_with_stdio(false);
	int t;
	cin>>t;	
	while(t--)
	{
		int n;
		cin>>n;
		cin>>(a+1);
		cin>>(b+1);
		for(int i=1;i<=n+2;++i)
		{
			suma[i]=suma[i-1];
			sumb[i]=sumb[i-1];
			sum[i]=sum[i-1];
			if(i<=n)
			{
				if(a[i]=='0')++suma[i];
				if(b[i]=='0')++sumb[i];
				if(a[i]!=b[i])++sum[i];
			}
		}
		int ans=sum[n];
		for(int i=1;i<=n+1;++i)
		{
			if(a[i]!='1')
			{
				int tmp=suma[i-1]+i-1-sumb[i-1];
				if(b[i]!='1')++tmp;
				tmp+=sum[n+2]-sum[i];
				ans=min(ans,tmp+1);
			}	
			else 
			{
				int tmp=suma[i-1]+i-1-sumb[i-1];
				if(b[i]!='1')++tmp;
				tmp+=sum[n+2]-sum[i];
				ans=min(ans,tmp+2);
			}		
		}
		for(int i=1;i<=n;++i)a[i]=b[i]=' ';
		printf("%d\n",ans);
	}
	return 0;
}
