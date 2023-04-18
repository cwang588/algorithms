//线性筛 
#include<bits/stdc++.h>
using namespace std;
bool isPrime[10000001];
int Prime[10000001],cnt=0;
void GetPrime(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i])
            Prime[++cnt] = i; 
        for(int j = 1; j <= cnt && i*Prime[j] <= n/*不超上限*/; j++) 
        {
            isPrime[ i*Prime[j] ] = 0;
            if(i % Prime[j] == 0)
                break;
        }
    }
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	GetPrime(n);
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(isPrime[t])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
