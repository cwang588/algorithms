#include<bits/stdc++.h>
using namespace std;
long long f[500];
int main()
{
	f[1]=1,f[2]=1;
	for(int i=3;i<=50;++i)
	{
		f[i]=f[i-1]+f[i-2];
	}
	for(int n=2;n<=20;++n)
		printf("%.17lf\n",(double)f[3*n-1]/f[3*n-2]);
	return 0;
}
