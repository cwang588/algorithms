#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		long long Max=0;
		for(int i=1;i<=n;++i)Max=max(a[i],Max);
		long long tot=0;
		for(int i=1;i<=n;++i)tot+=a[i];
		long long ans=(n-1)*Max-tot;
		if(ans<0)ans=(ans%(n-1)+n-1)%(n-1);
		cout<<ans<<"\n"; 
	}
	
	
	return 0;
}