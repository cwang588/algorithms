#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		bool ky=true;
		for(int i=2;i<=n;++i)if(a[i]%a[1])ky=false;
		if(ky)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}