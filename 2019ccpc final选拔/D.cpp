#include<bits/stdc++.h>
using namespace std;
char a[505][505];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>a[i][j];
	if(n==1)
	{
		int ans=0;
		for(int i=2;i<m;++i)if(a[1][i]=='.')++ans;
		return !printf("%d",ans);
	}
	if(m==1)
	{
		int ans=0;
		for(int i=2;i<n;++i)if(a[i][1]=='.')++ans;
		return !printf("%d",ans);
	}	
	if(n==2)
	{
		int ans=0;
		for(int i=2;i<m;++i)if(a[1][i]=='.'&&a[2][i]=='.')++ans;
		return !printf("%d",ans);
	}
	if(m==2)
	{
		int ans=0;
		for(int i=2;i<n;++i)if(a[i][1]=='.'&&a[i][2]=='.')++ans;
		return !printf("%d",ans);
	}
	int ans=0;
	for(int i=2;i<n;++i)
		for(int j=2;j<m;++j)
			if(a[i][j]=='.')
				++ans;
	bool ky=false;
	for(int i=2;i<n;++i)if(a[i][1]=='#')ky=true;
	for(int i=2;i<n;++i)if(a[i][m]=='#')ky=true;
	for(int i=2;i<m;++i)if(a[1][i]=='#')ky=true;
	for(int i=2;i<m;++i)if(a[n][i]=='#')ky=true;
	if(!ky)++ans;
	printf("%d\n",ans);
	return 0;
}
