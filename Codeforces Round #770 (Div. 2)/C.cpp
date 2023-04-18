#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(k==1){
			cout<<"YES\n";
			for(int i=1;i<=n;++i)cout<<i<<"\n";
			continue;
		}
		if(n%2==1){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		int now1=1,now2=2;
		for(int i=1;i<=n;++i){
			if(i%2){
				for(int j=1;j<=k;++j){
					cout<<now1<<" ";
					now1+=2;
				}
			}
			else{
				for(int j=1;j<=k;++j){
					cout<<now2<<" ";
					now2+=2;
				}
			}
			cout<<"\n";
		}
	}
	
	return 0;
}