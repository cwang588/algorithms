#include<bits/stdc++.h>
using namespace std;
long long a[100065];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<n;++i)ans=max(ans,a[i]*a[i+1]);
		cout<<ans<<endl;
	}
	return 0;
}
