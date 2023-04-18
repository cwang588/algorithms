#include<bits/stdc++.h>
using namespace std;
long long calc(int n,int m)
{
	long long ans=0;
	for(int i=1;i<n;++i)
		for(int j=1;j<m;++j)
			for(int k=i+1;k<=n;++k)
				for(int o=j+1;o<=m;++o)
					ans+=(i-1)*(j-1)*(n-k)*(m-o);
	return ans;
}
int main()
{
	for(int i=2;i<=15;++i)
	{
		for(int j=2;j<=15;++j)
			printf("%5lld ",calc(i,j));
		printf("\n");
	}
	return 0;
}
