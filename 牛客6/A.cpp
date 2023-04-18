#include<cstdio>
using namespace std;
int main()
{
	long long n,m;
	scanf("%lld%lld",&n,&m); 
	if(n>9*m||n<6*m)
		return !printf("jgzjgzjgz");
	printf("%lld",(7*m-n)>0?(7*m-n):0);	
	return 0;
}
