#include<bits/stdc++.h>
using namespace std;
bool isPrime[50005];
int Prime[50005],cnt=0;
void GetPrime(int n)
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1]=0;
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
long long getans(int now){
	int l=0,r=cnt;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(Prime[mid]<now)l=mid;
		else r=mid;
	}
	return Prime[r];
}
int main(){
	int t;
	scanf("%d",&t);
	GetPrime(50005);
	while(t--){
		int n;
		scanf("%d",&n);
		long long ans=getans(n+1);
		ans*=getans(ans+n);
		printf("%I64d\n",ans);
	}
	return 0;
}
