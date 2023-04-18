#include<bits/stdc++.h>
using namespace std;
int prime[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
bool usd[1000005];
map<int,int>m;
int num[100005],cnt[1005];
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
bool isPrime[10000001];
int Prime[10000001],cntt=0;
void GetPrime(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i])
            Prime[++cntt] = i; 
        for(int j = 1; j <= cntt && i*Prime[j]<=n; j++) 
        {
            isPrime[ i*Prime[j] ] = 0;
            if(i % Prime[j] == 0)
                break;
        }
    }
}
int main()
{
	GetPrime(1000000);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&num[i]);
		if(num[i]>1000&&isPrime[num[i]])
			m[num[i]]++;
	}
	int now=0;
	for(int i=1;i<=n;++i)
		now=gcd(num[i],now);
	for(int i=1;i<=n;++i)
	{
		num[i]/=now;
		usd[num[i]]=true;
	}
	for(int i=1;i<=168;++i)
		for(int j=1;prime[i]*j<=1000000;++j)
			if(usd[prime[i]*j])
			{
				++cnt[prime[i]];
				if(j<=1000)
					usd[j]=true;
				else
					++m[j];
			}
	int ans=0;
	for(int i=1;i<=168;++i)
		ans=max(ans,cnt[prime[i]]);
	for(int i=1001;i<=100000;++i)
		ans=max(ans,m[i]);
	printf("%d\n",n-ans);
	return 0;
}
