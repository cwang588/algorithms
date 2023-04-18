#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		if(n==1&&m==1)cout<<k<<endl;
		else cout<<n*m*k-k+1<<endl;
	}
	
	return 0;
}
