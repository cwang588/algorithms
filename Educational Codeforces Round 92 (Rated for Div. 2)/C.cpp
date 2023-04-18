#include<bits/stdc++.h>
using namespace std;
char s[200005];
int num[15];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		memset(num,0,sizeof(num));
		cin>>(s+1);
		int n=strlen(s+1);
		int ans=2147483647;
		for(int i=1;i<=n;++i)++num[s[i]-'0'];
		for(int i=0;i<=9;++i)ans=min(ans,n-num[i]);
		for(int i=0;i<=9;++i)
			for(int j=0;j<=9;++j)
			{
				if(i==j)continue;
				int now=i,tot=0;
				for(int k=1;k<=n;++k)
				{
					if(s[k]-'0'==now)
					{
						++tot;
						if(now==i)now=j;
						else
						{
							now=i;
							ans=min(ans,n-tot);
						}
					}
				}
			}
		cout<<ans<<"\n";
	}
	return 0;
}
