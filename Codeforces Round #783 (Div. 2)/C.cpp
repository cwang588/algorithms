#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	long long ans=1e18;
	for(int i=0;i<=n+1;++i){
		long long now=0,last=0;
		for(int j=i+1;j<=n;++j){
			long long tmp=last/a[j]*a[j];
			now+=last/a[j];
			while(tmp<=last){
				++now;
				tmp+=a[j];
			}
			last=tmp;
		}
		last=0;
		for(int j=i-1;j>=1;--j){
			long long tmp=last/a[j]*a[j];
			now+=last/a[j];
			while(tmp<=last){
				++now;
				tmp+=a[j];
			}
			last=tmp;
		}
		ans=min(ans,now);
	}
	cout<<ans<<'\n';
	return 0;
}