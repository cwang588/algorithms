#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=min(n,m);++i)cout<<"01";
		for(int i=1;i<=n-min(n,m);++i)cout<<"0";
		for(int i=1;i<=m-min(n,m);++i)cout<<"1";
		cout<<"\n";
	}
	
	return 0;
}