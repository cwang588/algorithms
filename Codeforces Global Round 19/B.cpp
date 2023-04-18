#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;++i){
			ans+=i*(n-i+1);
			int tmp;
			cin>>tmp;
			if(!tmp)ans+=i*(n-i+1);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}