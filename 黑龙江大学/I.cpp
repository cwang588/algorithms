#include<bits/stdc++.h>
using namespace std;
bool prime[20000005];
int Prime[20000005];
int prime_num;
long long ans[1500005];
void make_prime(int MAXN)
{
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=2;i<=MAXN;i++)
    {
        if(prime[i])
        {
            Prime[++prime_num]=i;
        }
        for(int j=1;j<=prime_num&&i*Prime[j]<MAXN;j++)
        {
            prime[i*Prime[j]]=false;
            if(!(i%Prime[j]))
                break;
        }
    }
    return;
} 
int main()
{
	freopen("test.in","r",stdin);
	freopen("test1.out","w",stdout);
	int n;
	scanf("%d",&n);
	make_prime(n*2); 
	for(int i=2;i<=n;++i)
		ans[i]=(i-1)*(i-1);
	ans[1]=0;
	for(int i=1;i<=prime_num;++i)
		ans[Prime[i]]=(long long)(Prime[i]-1)*(Prime[i]-1);
	for(int i=4;i<=n;++i)
	{
		if(!prime[i])
		{
			int tt=i,now=1;
			while(!prime[tt])
				if(i%Prime[now]==0)
					ans[i]=min(ans[i],ans[i/Prime[j]]+(i-i/Prime[j])*(i-i/Prime[j]));
		}
	}
	for(int i=1;i<=n;++i)
		printf("%lld ",ans[i]);
	return 0;
}
