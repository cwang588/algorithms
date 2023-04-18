#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
//	if(n==2){
//		if(m!=1)cout<<"-1\n";
//		else cout<<"1 2\n";
//		return 0;
//	}
	if(m<n-1||m>2*n-3){
		cout<<"-1\n";
		return 0;
	}
	for(int i=2;i<=n;++i){
		if(m){
			--m;
			cout<<"1 "<<i<<"\n"; 
		}
	}
	for(int i=n-1;i>=2;--i){
		if(m){
			--m;
			cout<<i<<" "<<n<<"\n";
		}
	}
	return 0;
}