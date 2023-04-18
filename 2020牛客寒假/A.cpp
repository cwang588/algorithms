#include<bits/stdc++.h>
using namespace std;
char s1[100050],s2[100050];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>s1[i];
	for(int i=1;i<=m;++i)cin>>s2[i];
	int tmp=min(n,m),ans=0;
	for(int i=1;i<=tmp;++i)if(s1[i]!=s2[i])++ans;
	printf("%d\n",ans+abs(n-m));
	return 0;
}
