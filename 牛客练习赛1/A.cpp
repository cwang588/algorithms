#include<bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
unordered_map<ull,int>mm;
ull Hash[1005][1005],a=19260817,b=100000007,aa[1005],bb[1005];
char c[1005][1005];
ull gethash(int x,int y,int z)
{
	return Hash[x][y]-Hash[x-z][y]*bb[z]-Hash[x][y-z]*aa[z]+Hash[x-z][y-z]*aa[z]*bb[z];
}
void init()
{
	aa[0]=bb[0]=1;
	for(int i=1;i<=1000;++i)
	{
		aa[i]=aa[i-1]*a;
		bb[i]=bb[i-1]*b;
	}
}
int n,m;
bool judge(int len)
{
	mm.clear();
	for(int i=len;i<=n;++i)
		for(int j=len;j<=m;++j)
			{
				ull now=gethash(i,j,len);
				if(mm[now])return true;
				++mm[now];
			}
	return false;
}
int main()
{
	ull hashnow=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>c[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			Hash[i][j]=Hash[i][j-1]*a+c[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			Hash[i][j]+=Hash[i-1][j]*b;	
	init();
	int l=1,r=min(n,m);
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(judge(mid))l=mid;
		else r=mid;
	}
	if(judge(r))printf("%d\n",r);
	else printf("%d\n",l);
	return 0;
}
