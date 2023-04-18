//O(n)Çó1-nÄæÔª 
#include<bits/stdc++.h>
using namespace std;
long long inv[3000006];
int main()
{
	long long n,p;
	scanf("%lld%lld",&n,&p);
	inv[1]=1;
	for(long long i=2;i<=n;++i)
		inv[i]=(p-p/i)*inv[p%i]%p;
	for(long long i=1;i<=n;++i)
		printf("%lld\n",inv[i]);
	return 0;
}
