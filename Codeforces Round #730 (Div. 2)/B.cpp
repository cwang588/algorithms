#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long tot=0;
		for(int i=1;i<=n;++i){
			long long tmp;
			cin>>tmp;
			tot+=tmp;
		}
		long long mod=tot%n;
		cout<<mod*(n-mod)<<endl;
	}
	return 0;
}
