#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int cnt=0;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			if(a[i]<0){
				a[i]*=-1;
				++cnt;
			}
		}
		bool ky=true;
		for(int i=2;i<=cnt;++i){
			if(a[i]>a[i-1]){
				ky=false;
				break;
			}
		}
		for(int i=cnt+2;i<=n;++i){
			if(a[i]<a[i-1]){
				ky=false;
				break;
			}
		}
		if(ky)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	
	return 0;
}