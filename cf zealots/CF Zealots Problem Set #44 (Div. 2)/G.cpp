#include<bits/stdc++.h>
using namespace std;
int a[15];
long long p[15];
long long getp(int x){
	long long re=1;
	while(x--)re*=10;
	return re;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;++i)cin>>a[i],p[i]=getp(a[i]);
		if(a[1]!=0){
			cout<<"1\n";
			continue;
		}
		long long ans=0;
		for(int i=1;i<n;++i){
			if(p[i]*(k+1)<p[i+1]){
				ans+=p[i]*(k+1);
				k=0;
				break;
			}
			long long cnt=(p[i+1]-p[i])/p[i];
			k-=cnt;
			ans+=cnt*p[i];	
			if(k==0){
				ans+=p[i+1];
				break;
			}
		}
		if(k)ans+=(k+1)*p[n];
		cout<<ans<<"\n";
	}
	
	
	return 0;
}