#include<bits/stdc++.h>
using namespace std;
unordered_map<long long,int>sg;
bool isPrime[10000005];
int Prime[10000005],cnt=0;
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
int a[15];
int getsg(long long now)
{
	if(now==1)return 0;
	vector<int>v,num;
	bool usd[75],ky=true;
	if(now%2==0)usd[0]=true;
	for(int i=1;(long long)Prime[i]*(long long)Prime[i]<=now;++i)
	{
		if(now%Prime[i]==0)v.push_back()
	}
	if(ky)return 1;
	for(int i=0;;++i)if(!usd[i])return i;
}
int main()
{
	int t;
	scanf("%d",&t);
	GetPrime(200005);
	for(int i=1;i<=50;++i)
	{
		sg[i]=getsg(i);
		printf("%d:%d\n",i,sg[i]);
	}
//	while(t--)
//	{
//		int n;
//		scanf("%d",&n);
//		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
//		sg[1]=0;
//		for(int i=1;i<=n;++i)sg[a[i]]=getsg(a[i]);
//		int now=0;
//		for(int i=1;i<=n;++i)now^=sg[a[i]];
//		if(!now)printf("L\n");
//		else printf("W\n");
//	}
	return 0;
}
