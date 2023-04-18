#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool ky=false;
		for(int i=1;i*i<=n;++i){
			if(n%i)continue;
			if(2*i>=n/i){
				ky=true;
				break;
			}
		}
		if(ky)cout<<"1\n";
		else cout<<"0\n";
	}
	
	return 0;
}
