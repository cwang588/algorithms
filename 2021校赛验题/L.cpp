#include<bits/stdc++.h>
using namespace std;
int a[1005],prime[100005],cnt;
bool usd[100005],ky[100005];
unordered_map<long long,long long>m;
void init(int n){
	usd[1]=true;
	for(int i=1;i<=n;++i){
		if(!usd[i])prime[++cnt]=i;
		for(int j=1;j<=cnt&&prime[j]*i<=n;++j){
			usd[prime[j]*i]=true;
			if(i%prime[j]==0)break;
		}
	}
}
int main(){
	init(100000);
	int n;
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		long long tmp=a[i];
		for(int j=1;prime[j]*prime[j]<=tmp;++j){
			if(tmp%prime[j]==0){
				m[prime[j]]+=a[i];
				ans=max(ans,m[prime[j]]);
				while(tmp%prime[j]==0)tmp/=prime[j];
			}
		}
		if(tmp>1){
			m[tmp]+=a[i];
			ans=max(m[tmp],ans);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
