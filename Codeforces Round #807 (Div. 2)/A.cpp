#include<bits/stdc++.h>
using namespace std;
int a[2055];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		for(int i=1;i<=n*2;++i)cin>>a[i];
		sort(a+1,a+1+n*2);
		bool ky=true;
		for(int i=1;i<=n;++i){
			if(a[i]+x>a[i+n]){
				ky=false;
				break;
			}
		}
		if(ky)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}