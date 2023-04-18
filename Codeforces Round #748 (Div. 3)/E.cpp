#include<bits/stdc++.h>
using namespace std;
long long a[105],tmp[105];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];	
		sort(a+1,a+1+n);
		long long ans=-1;
		bool answered=false;
		for(int i=1;i<=n/2+1;++i){
			int zero=0;
			for(int j=1;j<=n-i;++j){
				tmp[j]=a[i+j]-a[i];
				if(!tmp[j])++zero;
			}
			if(zero+1>=n/2){
				cout<<"-1\n";
				answered=true;
				break;
			}
			set<long long>s;
			for(int j=1;j<=n-i;++j){
				for(int k=1;k*k<=tmp[j];++k){
					if(tmp[j]%k==0){
						s.insert(k);
						s.insert(tmp[j]/k);
					}
				}
			}
			for(auto x:s){
				int cnt=0;
				for(int j=1;j<=n-i;++j){
					if(tmp[j]%x==0)++cnt;
				}
				if(cnt+1>=n/2)ans=max(ans,x);
			}
		}
		if(!answered)cout<<ans<<"\n";
	}
	return 0;
}