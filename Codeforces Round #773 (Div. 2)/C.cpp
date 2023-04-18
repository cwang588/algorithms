#include<bits/stdc++.h>
using namespace std;
long long a[400005];
map<long long,int>cnt;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		for(int i=1;i<=n;++i)cin>>a[i],++cnt[a[i]];
		sort(a+1,a+1+n);
		int ans=0;
		for(int i=1;i<=n;++i){
			if(!cnt[a[i]])continue;
			if(!cnt[a[i]*x])++ans;
			else --cnt[a[i]*x];
			--cnt[a[i]];
		}
		cout<<ans<<"\n";
		cnt.clear();
	}
	
	
	return 0;
}