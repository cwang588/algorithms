#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		int ans=0;
		for(int i=2;i<n;++i){
			if(a[i]>a[i-1]&&a[i]>a[i+1]){
				a[i+1]=max(a[i],a[i+2]);
				++ans;
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;++i)cout<<a[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}