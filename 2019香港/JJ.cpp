#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=3e5+10;
char l[maxn],r[maxn];
ll dp[5009][75][75];
int ppow[5009],a[5009],en,n,m;
int dfs(int len,int limit,int nowmod,int sumn)
{
//nowmod是当前数对m的和,he是前缀和, 
	if( len==0 )	return !nowmod;
	if( !limit&&dp[len][nowmod][sumn]!=-1 )
		return dp[len][nowmod][sumn];
	ll last=limit?a[len]:9,ans=0;
	for(int i=0;i<=last;i++)
	{
		int fx=nowmod+sumn*i-i*ppow[len-1]+m;
		ans+=dfs(len-1,limit&&(i==a[len]),(fx%m+m)%m,(sumn+i)%m);
	}
	ans=(ans%mod+mod)%mod;
	if( !limit )	dp[len][nowmod][sumn]=ans;
	return ans;
}
int solve(char b[])
{
	en=strlen(b+1);
	for(int i=0;i<=en;i++)
	for(int j=0;j<m;j++)
	for(int q=0;q<m;q++)
		dp[i][j][q]=-1;
	for(int i=1;i<=en;i++)
		a[i]=b[en-i+1]-'0';
	return dfs(en,1,0,0);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ppow[0]=1;
	int t; cin >> t;
	while( t-- )
	{
		cin >> (l+1) >> (r+1);
		cin >> m;
		int rr=strlen(r+1);
		for(int i=1;i<=rr;i++)	ppow[i]=ppow[i-1]*10%m;
		int en=strlen(l+1);
		l[en]--;
		for(int i=en;i>=1;i--)
			if( l[i]<'0' )	l[i]+=10,l[i-1]--;
			else	break;
		cout << ( solve(r)-solve(l)+mod )%mod << '\n';
	}
}

