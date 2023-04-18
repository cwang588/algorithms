#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool tong[10000007];
bool isPrime[6505];
int Prime[6505],cnt;
void init(int n)
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
int main(){
	init(6000);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			int now=a[i],tmp=1;
			for(int j=1;Prime[j]<=3500;++j){
				if(now%Prime[j]==0){
					int num=0;
					while(now%Prime[j]==0){
						++num;
						now/=Prime[j];
					}
					if(num%2)tmp*=Prime[j];
				}
			}
			if(now)tmp*=now;
			a[i]=tmp;
		}
		int ans=1,last=1;
		tong[a[1]]=true;
		for(int i=2;i<=n;++i){
			if(tong[a[i]]){
				for(int j=last;j<i;++j)tong[a[j]]=false;
				++ans;
				last=i;
			}
			tong[a[i]]=true;
		}
		for(int i=last;i<=n;++i)tong[a[i]]=false;
		printf("%d\n",max(1,ans-k));
	}
	return 0;
}
