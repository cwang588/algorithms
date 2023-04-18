#include<bits/stdc++.h>
using namespace std;
map<long long,bool>m;
bool isPrime[10000005];
int Prime[10000005],cnt=0;
int type[15];
void GetPrime(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i])
            Prime[++cnt] = i; 
        for(int j = 1; j <= cnt && Prime[j] <= n/i/*²»³¬ÉÏÏÞ*/; j++) 
        {
            isPrime[ i*Prime[j] ] = 0;
            if(i % Prime[j] == 0)
                break;
        }
    }
}
void init()
{
	long long now=2;
	while(now<=1000000000)
	{
		m[now]=true;
		now*=2;
	}
}
int main()
{
	init();
	GetPrime(200000);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int num=0;
		for(int i=1;i<=n;++i)
		{
			long long x;
			scanf("%lld",&x);
			if(x==1)
			{
				type[i]=0;
				continue;
			}
			int tmp=0;
			if(m[x]==true)tmp=0;
			else
			{
				for(int j=1;(long long)Prime[j]*(long long)Prime[j]<=x;++j)
				{
					if(x%Prime[j]==0)
					{
						tmp=1;
						break;
					}
				}
			}
			if(tmp)type[i]=2,++num;
			else type[i]=1;
		}
		int tnum=0;
		for(int i=1;i<=n;++i)if(type[i]==1)++tnum;
		if(num>0)
		{
			if(num%2)printf("W\n");
			else 
			{
				if(tnum%2==0)printf("L\n");
				else printf("W\n");
			}
		}
		else
		{
			if(tnum%2)printf("W\n");
			else printf("L\n");
		}
	}
	return 0;
}
