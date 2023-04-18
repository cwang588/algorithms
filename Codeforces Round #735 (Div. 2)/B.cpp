#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;++i)cin>>a[i];
		long long ans=-2147483647;
		for(int i=2;i<=n;++i){
			for(int j=max(1,i-(100*n/i+1));j<i;++j)ans=max(ans,(long long)i*j-k*(a[i]|a[j]));
		}
		cout<<ans<<endl;
	}
	return 0;
}
