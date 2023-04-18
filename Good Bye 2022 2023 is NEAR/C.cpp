#include<bits/stdc++.h>
using namespace std;
long long a[105];
int cnt[55];
int main(){
	int t;
	cin>>t;
	while(t--){
		unordered_map<long long,bool>usd;
		int n;
		cin>>n;
		bool nb=true;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			if(usd[a[i]])nb=false;
			usd[a[i]]=true;
		}
		if(!nb){
			cout<<"NO\n";
			continue;
		}
		for(int i=2;i<=50;++i){
			memset(cnt,0,sizeof(cnt));
			for(int j=1;j<=n;++j)++cnt[a[j]%i];
			bool ky=false;
			for(int j=0;j<i;++j){
				if(cnt[j]<2){
					ky=true;
					break;
				}
			}
			if(!ky){
				nb=false;
				break;
			}
		}
		if(nb)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	
	return 0;
}