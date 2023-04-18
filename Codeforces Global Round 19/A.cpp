#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,tmp,last=0;
		cin>>n;
		bool ky=false;
		while(n--){
			cin>>tmp;
			if(tmp<last)ky=true;
			last=tmp;
		}
		if(ky)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}