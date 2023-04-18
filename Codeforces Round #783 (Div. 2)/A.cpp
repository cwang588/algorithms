#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(n==1&&m==1){
			cout<<"0\n";
			continue;
		}		
		if(n==1){
			if(m==2)cout<<"1\n";
			else cout<<"-1\n";
			continue;
		}
		if(m==1){
			if(n==2)cout<<"1\n";
			else cout<<"-1\n";
			continue;
		}
		int ans=(min(n,m)-1)*2;
		if(n==m){
			cout<<ans<<"\n";
			continue;
		}
		int gap=abs(n-m);
		ans+=gap/2*4+gap%2;
		cout<<ans<<"\n";
	}	
	
	return 0;
}