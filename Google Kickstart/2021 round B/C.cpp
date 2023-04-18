#include<bits/stdc++.h>
using namespace std;
bitset<1000000255>isPrime;
int Prime[60848535],cnt;
void GetPrime(int n)
{
	isPrime.flip();
    isPrime[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i])
            Prime[++cnt] = i; 
        for(int j = 1; j <= cnt && Prime[j] <= n/i; j++) 
        {
            isPrime[ i*Prime[j] ] = 0;
            if(i % Prime[j] == 0)
                break;
        }
    }
}
int main(){
	GetPrime(1000000150);
//	cout<<sizeof(isPrime)<<" "<<sizeof(Prime)<<" "<<sizeof(isPrime)+sizeof(Prime)<<"\n";
//return 0;
	int t;
	cin>>t;
	
	for(int Case=1;Case<=t;++Case){
		long long n;
		cin>>n;
		int l=1,r=cnt;
		while(l<r-1){
			int m=(l+r)>>1;
			if(1ll*Prime[m]*Prime[m+1]<=n)l=m;
			else r=m;
		}
		cout<<"Case #"<<Case<<": "<<1ll*Prime[l]*Prime[l+1]<<"\n";
	}
	
	
	return 0;
}