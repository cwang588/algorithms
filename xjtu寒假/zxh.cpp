#include<bits/stdc++.h>
using namespace std;
bool isPrime[10000005];
int sum[10000005];
int Prime[10000005],cnt;
void GetPrime(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i])
            Prime[++cnt] = i; 
        for(int j = 1; j <= cnt && i*Prime[j] <= n/*²»³¬ÉÏÏÞ*/; j++) 
        {
            isPrime[ i*Prime[j] ] = 0;
            if(i % Prime[j] == 0)
                break;
        }
    }
    for(int i=1;i<=n;++i)
    {
    	sum[i]=sum[i-1];
    	if(i==1||isPrime[i]==1)++sum[i];
    }
}
int main()
{
	GetPrime(10000005);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",sum[r]-sum[l-1]);
	}
	return 0;
}
