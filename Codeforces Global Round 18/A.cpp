#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		long long tot=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			long long tmp;
			cin>>tmp;
			tot+=tmp;
		}
		if(tot%n)cout<<"1\n";
		else cout<<"0\n";
	}
	
	
	return 0;
}