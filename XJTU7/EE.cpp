#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6+7;
bool vis[MAXN];
double Gu[105][105];
int phi[MAXN], prime[MAXN];
int cnt;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
void Euler(int n)
{
    phi[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!vis[i])
        {
            prime[++cnt] = i;
            phi[i] = i-1;
        }
        for(int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}
int main()
{
	freopen("db.txt","w",stdout);
	Euler(100005);
	for(int i=1;i<=50;++i)
	{
		for(int j=1;j<=50;++j)
		{
			int t=gcd(phi[i*j],phi[i]*phi[j]);
		//	printf("%2d %2d  ",phi[i*j]/t,phi[i]*phi[j]/t);
			printf("%3d ",gcd(i,j));
		}
		printf("\n");
	}
	return 0;
}
