#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n%2==0){
		for(int i=1;i<=n/2;++i){
			if(i%2)cout<<"10";
			else cout<<"01";
		}
	}
	else{
		if(n==3)cout<<"Unlucky";
		else{
			cout<<"01010";
			for(int i=1;i<=(n-5)/2;++i){
				if(i%2)cout<<"01";
				else cout<<"10";
			}
		}
	}
	return 0;
}