#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		long long ans=0;
		bool ky=false;
		for(int i=1;i<n;++i){
			ans+=a[i];
			if(a[i])ky=true;
			else{
				if(ky)++ans;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}