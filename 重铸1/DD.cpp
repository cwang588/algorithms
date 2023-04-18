#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.txt","w",stdout);
	cout<<"100"<<endl;
	for(int i=1;i<=5;++i){
		int n=20,m=190;
		cout<<n<<" "<<m<<endl;
		for(int j=1;j<=n;++j){
			for(int k=j+1;k<=n;++k)cout<<j<<" "<<k<<endl;
		}
	}
	for(int i=1;i<=95;++i){
		int n=10,m=45;
		cout<<n<<" "<<m<<endl;
		for(int j=1;j<=n;++j){
			for(int k=j+1;k<=n;++k)cout<<j<<" "<<k<<endl;
		}
	}
	return 0;
}
