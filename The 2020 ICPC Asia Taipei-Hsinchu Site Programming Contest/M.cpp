#include<bits/stdc++.h>
using namespace std;
int a[5],b[5];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=m;++i)cin>>b[i];
		if(n==1||m==1)cout<<'1'<<endl;
		else cout<<'7'<<endl; 
	}
	return 0;
}
