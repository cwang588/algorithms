#include<bits/stdc++.h>
using namespace std;
long long f[55][55];
int main()
{
	for(int i=0;i<=20;++i)f[i][0]=1;
	for(int i=1;i<=20;++i)
		for(int j=1;j<=18;++j)
		{
			if(i<=j)break;
			f[i][j]=f[i-1][j]+f[i][j-1];
		}
	printf("%lld\n",f[20][18]);
	return 0;
}
