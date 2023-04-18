#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n>19)cout<<"NO\n";
		else{
			cout<<"YES\n";
			int now=1;
			for(int i=1;i<=n;++i){
				cout<<now<<" ";
				now*=3;
			}
			cout<<"\n";
		}
	}
	
	return 0;
}