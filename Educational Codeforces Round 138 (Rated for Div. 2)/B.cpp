#include<bits/stdc++.h>
using namespace std;
long long a[200006],b[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)cin>>b[i];
		long long ans=0,Max=0;
		for(int i=1;i<=n;++i){
			ans+=a[i]+b[i];
			Max=max(Max,b[i]);
		}
		cout<<ans-Max<<"\n";
	}
	
	return 0;
}