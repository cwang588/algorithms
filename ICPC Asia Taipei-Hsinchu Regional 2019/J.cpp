#include<bits/stdc++.h>
using namespace std;
char s[25][505];
bool usd[505];
int cnt[633355];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i=1;i<=65536;++i)
		for(int j=0;j<=15;++j)
			if((1<<j)&i)
				++cnt[i];
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
				cin>>s[i][j];
		int ans=999999;
		for(int i=1;i<=(1<<m);++i)
		{
			memset(usd,0,sizeof(usd));
			int tmp=0;
			if(cnt[i]>=ans)continue;
			for(int j=0;(1<<j)<=i;++j)
			{
				if((1<<j)&i)
				{
					for(int k=1;k<=n;++k)
						if(s[j+1][k]=='1')
							usd[k]=true;
					++tmp;
				}
			}
			bool ky=true;
			for(int k=1;k<=n;++k)
				if(!usd[k])
				{
					ky=false;
					break;
				}
			if(ky)ans=min(tmp,ans);
		}
		if(ans==999999)cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
