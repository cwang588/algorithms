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
        for(int j = 1; j <= cnt && i*Prime[j] <= n/*²»³¬ÉÏÏÞ*/; j++) 
        {
            isPrime[ i*Prime[j] ] = 0;
            if(i % Prime[j] == 0)
                break;
        }
    }
}
int main()
{
	int n;
	scanf("%d",&n);
	GetPrime(20000);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		if(isPrime[t])
			printf("%d 0\n",t);
		else
		{
			int ans=9999999;
			for(int j=1;j<=cnt;++j)
				ans=min(ans,abs(t-Prime[j]));
			printf("%d %d\n",t,ans);
		}
	}
	return 0;
}
