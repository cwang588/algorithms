#include<bits/stdc++.h>
using namespace std;
long long fac[25];
int calc(long long x){
	int re=0;
	while(x){
		if(x&1)++re;
		x>>=1;
	}
	return re;
}
int main(){
	fac[0]=1;
	for(int i=1;i<=14;++i)fac[i]=fac[i-1]*i;
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		int ans=2147483647;
		for(int i=0;i<(1<<14);++i){
			int cnt=0;
			long long tot=0;
			for(int j=0;j<14;++j){
				if((1<<j)&i)++cnt,tot+=fac[j+1];
			}
			if(tot>n)continue;
			ans=min(ans,cnt+calc(n-tot));
		}
		cout<<ans<<"\n";
	}	
	
	
	return 0;
}