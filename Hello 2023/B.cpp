#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==2){
			cout<<"YES\n114 514\n";
			continue;
		}
		else if(n==3){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		for(int i=1;i<=n;++i){
			if(i%2)cout<<(n-2)/2<<" ";
			else cout<<-((n-3)/2+1)<<" ";
		}
		cout<<"\n";
	}
	
	
	return 0;
}