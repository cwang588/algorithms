#include<bits/stdc++.h>
using namespace std;
long long dis[35][35];
long long value[35][35];
long long cnt[2][35][100005];
int n,m,k;
char s[1000005];
long long ans;
void work(int i)
{
	for(int j=1;j<=26;++j)
	{
		int l=max(k-i+1,i),r=min(2*n-k-i+1,i+k-1);
		int pos=((k+1)%2+i%2)%2;
		ans+=value[s[i]-'a'+1][j]*(cnt[pos][j][r]-cnt[pos][j][l-1]);
	}
}
int main()
{
	freopen("01.in","r",stdin);
	//ios::sync_with_stdio(false);
	long long t;
	cin>>n>>m>>k>>t;
	for(int i=1;i<=26;++i)
		for(int j=1;j<=26;++j)
			dis[i][j]=value[i][j]=230584300921369392;
	for(int i=1;i<=n;++i)cin>>s[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=26;++j)cnt[0][j][i]=cnt[0][j][i-1],cnt[1][j][i]=cnt[1][j][i-1];
		++cnt[i%2][s[i]-'a'+1][i];
	}
	for(int i=1;i<=m;++i)
	{
		char x,y;
		long long c;
		cin>>x>>y>>c;
		dis[x-'a'+1][y-'a'+1]=min(dis[x-'a'+1][y-'a'+1],c);
	}
	for(int i=1;i<=26;++i)dis[i][i]=0;
	for(int k=1;k<=26;++k)
		for(int i=1;i<=26;++i)
			for(int j=1;j<=26;++j)
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	for(int i=1;i<=26;++i)
		for(int j=1;j<=26;++j)
			for(int k=1;k<=26;++k)
				value[i][j]=min(t,min(value[i][j],dis[i][k]+dis[j][k]));
	for(int i=1;i<=26;++i)
		for(int j=1;j<=26;++j)
			value[i][j]=min(value[i][j],value[j][i]);
	long long ans=0;
	for(int i=1;i<=n-k+1;++i)
	{
		work(i);
	}
	for(int i=n-k+2;i<=n-k/2;++i)ans+=value[s[i]-'a'+1][s[2*(n-k/2)-i]-'a'+1];
	cout<<ans;
	return 0;
}
