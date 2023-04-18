#include<cstdio>
using namespace std;
const long long N=1e9+7;
long long mi(long long a,long long b)
{
	if(a%2)
		return (((mi(a/2,b)*a)%N)*mi(a/2,b))%N;
	else
		return (mi(a/2,b)*mi(a/2,b))%N;
}
int main()
{
	int n,k,x;
	scanf("%d%d%d",&n,&k,&x);
	long long b=1;
	for(int i=2;i<=k;++i)
		b=(b*i)%N;
	b=(b*mi(100,n))%N;
	long long t=mi(b,N-2);
	
	return 0;
}
