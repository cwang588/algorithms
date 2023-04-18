#include<bits/stdc++.h>
using namespace std;
char s[200005];
int sum[200005][30],pos[200005][30];
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i];
		for(int j=0;j<=25;++j)sum[i][j]=sum[i-1][j];
		++sum[i][s[i]-'a'];
		pos[sum[i][s[i]-'a']][s[i]-'a']=i;
	}
	int ans=2147483647;
	for(int i=0;i<=25;++i)
		for(int j=1;j<=n;++j)
			if(sum[j][i]>=k)
				ans=min(ans,j-pos[sum[j][i]-k+1][i]+1);
	printf("%d\n",ans==2147483647?-1:ans);
	return 0;
}
