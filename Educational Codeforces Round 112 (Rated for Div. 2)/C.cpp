#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			a[i]+=a[i-1];
		}
		for(int i=1;i<=n;++i){
			cin>>b[i];
			b[i]+=b[i-1];
		}
		long long ans=2147483647;
		for(int i=1;i<=n;++i)ans=min(ans,max(a[n]-a[i],b[i-1]));
		cout<<ans<<endl;
	}
	return 0;
}
