#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y)
{
	return y?gcd(y,x%y):x;
}
long long calc(int n,int a,int b)
{
	long long re=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			if(gcd(i,j)==1)
			{
				re+=gcd(pow(i,a)-pow(j,a),pow(i,b)-pow(j,b));
			}
	return re;
}

int main()
{
	for(int i=1;i<=10;++i)
		printf("%d %lld\n",i,calc(i,5,
		
		));
	return 0;
}
