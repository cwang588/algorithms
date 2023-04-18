#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int hls[11][11];
int n;
int xl[11];
long long ans;
int nx()
{
	int tot=0;
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
			if(xl[i]>xl[j])
				++tot;
	if(tot%2)
		return -1;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&hls[i][j]);
	for(int i=1;i<=n;++i)
		xl[i]=i;
	int zf;
	zf=nx();
	long long tep=1;
	for(int i=1;i<=n;++i)
		tep*=hls[i][xl[i]];
	tep*=(unsigned long long)zf;
	ans+=tep;
	while(next_permutation(xl+1,xl+1+n))
	{
		tep=1;
		zf=nx();
		for(int i=1;i<=n;++i)
			tep*=hls[i][xl[i]];
		tep*=zf;
		ans+=tep;
	}
	cout<<ans;
	return 0;
} 	
