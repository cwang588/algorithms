#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
//bool isPrime[10000001];
//int Prime[10000001],cnt=0;
//void GetPrime(int n)
//{
//    memset(isPrime, 1, sizeof(isPrime));
//    isPrime[1] = 0;
//    for(int i = 2; i <= n; i++)
//    {
//        if(isPrime[i])
//            Prime[++cnt] = i; 
//        for(int j = 1; j <= cnt && i*Prime[j] <= n/*²»³¬ÉÏÏÞ*/; j++) 
//        {
//            isPrime[ i*Prime[j] ] = 0;
//            if(i % Prime[j] == 0)
//                break;
//        }
//    }
//}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int now=19260817;
	if(n==2)
		return !printf("2 2\n1 2 2");
	printf("2 %d\n",now);
	printf("1 %d 2\n",n);
	for(int i=2;i<n-1;++i)
		printf("%d %d 1\n",i,i+1);
	printf("%d %d %d\n",n-1,n,now-n+1);
	int tot=0;
	for(int i=1;i<n-1;++i)
		for(int j=i+2;j<=n;++j)
		{
			if(i==1&&j==n)
			 	continue;
			++tot;
			if(tot+n-1>m)
				return 0;
			printf("%d %d 1000000000\n",i,j);
		}
	if(m==n*(n-1)/2)
	printf("1 2 1000000000");
	return 0;
}
