#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==3){
			cout<<"3 2 1\n1 3 2\n3 1 2\n";
			continue;
		}
		for(int i=n;i>=1;--i){
			for(int j=i;j>=1;--j)cout<<j<<" ";
			for(int j=n;j>i;--j)cout<<j<<" ";
			cout<<"\n";
		}
	}
	
	
	return 0;
}