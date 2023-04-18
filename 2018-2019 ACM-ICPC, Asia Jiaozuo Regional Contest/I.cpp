#include<bits/stdc++.h>
using namespace std;
long long a[1000005],sum[1000005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=2;i<=n;++i)cin>>a[i],sum[i]=sum[i-1]+a[i];
		cout<<"0 "<<sum[n];
		if(n>2)cout<<" ";
		long long tot=sum[n],ans=sum[n];
		int l=1,r=n;
		for(int i=3;i<=n;++i){
			if(i%2){
				ans+=tot;
				cout<<ans;
				++l;
			}
			else{
				--r;			
				ans+=tot+sum[r]-sum[l];
				tot+=sum[r]-sum[l];
				cout<<ans;
			}
			if(i<n)cout<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
