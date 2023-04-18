#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
#define LL long long
#define mod 1000000007
LL F[55] = {1,1,2};
int s1[250], s2[250];
int main(void)
{
	LL n;
	int cnt, i, now;
	for(i=3;i<=50;i++)
		F[i] = F[i-1]+F[i-2];
	while(scanf("%lld", &n)!=EOF)
	{
		if(n==0)
			printf("2\n1 1\n2 2\n");
		else if(n==1)
			printf("2\n1 199\n2 2\n");
		else
		{
			now = 1, cnt = 0;
			while(n!=1)
			{
				if(n%2==0)
				{
					s1[++cnt] = now, s2[cnt] = now+2;
					s1[++cnt] = now+1, s2[cnt] = now;
					now += 3;
				}
				else
				{
					s1[++cnt] = now, s2[cnt] = 199;
					now += 2;
					s1[++cnt] = now, s2[cnt] = now+2;
					s1[++cnt] = now+1, s2[cnt] = now;
					now += 3;
				}
				n /= 2;
			}
			s1[++cnt] = now-1, s2[cnt] = 199;
			printf("%d\n", cnt);
			for(i=1;i<=cnt;i++)
				printf("%d %d\n", s1[i], s2[i]);
		}
	}
	return 0;
}
