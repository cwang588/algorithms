#include<cstdio>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
char f[5000005][25];
int pos[5000005][25];
char t[5000005];
int main()
{
	int n,m;
	for(int i=1;i<=5000000;++i)
		for(int j=0;j<=25;++j) 
			f[i][j]='|';
	cin>>t;
	n=strlen(t);
	for(int i=0;i<n;++i)
	{
		f[i+1][0]=t[i];
		pos[i+1][0]=i+1;
	}
	for(int j=1;j<=25;++j)
		for(int i=1;i+(1<<j)<=n+1;++i)
		{
			if(f[i][j]>f[i+(1<<(j-1))][j-1])
			{
				f[i][j]=f[i+(1<<(j-1))][j-1];
				pos[i][j]=pos[i+(1<<(j-1))][j-1];
			}
		}
	scanf("%d",&m);
	int now=0;
	for(int i=1;i<=m;++i)
	{
		int l=now+1,r=n-m+i;
		int k=log2(r-l+1);
		if(f[l][k]>f[r-(1<<k)+1][k])
		{
			printf("%c",f[r-(1<<k)+1][k]);
			now=pos[r-(1<<k)+1][k]+1;
		}
		else
		{
			printf("%c",f[l][k]);
			now=pos[l][k];			
		}
	}
	return 0;
}
