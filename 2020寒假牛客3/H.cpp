#include<bits/stdc++.h>
using namespace std;
map<int,int>mm;
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
int sum[1000005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    GetPrime(n);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j*j<=i;++j)
        {
            if(i%j==0)
            {
                if(!isPrime[j])++sum[i];
                if(j*j!=i&&!isPrime[i/j])++sum[i];
            }
        }
        --sum[i];
    }
    for(int i=1;i<=n;++i)++mm[sum[i]];
    for(int i=1;i<=m;++i)
    {
        int t;
        scanf("%d",&t);
        printf("%d\n",mm[t]);
    }
    return 0;
}
