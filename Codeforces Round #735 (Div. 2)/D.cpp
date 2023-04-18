#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<=26){
			for(int i=1;i<=n;++i)cout<<(char)('a'+i-1);
			cout<<endl;
		}
		else{
			if(n%2==0){
				for(int i=1;i<=n/2;++i)cout<<'a';
				cout<<'b';
				for(int i=1;i<n/2;++i)cout<<'a';
				cout<<endl;
			}
			else{
				for(int i=1;i<=n/2;++i)cout<<'a';
				cout<<"bc";
				for(int i=1;i<n/2;++i)cout<<'a';
				cout<<endl;
			}
		}
	}
	return 0;
}
