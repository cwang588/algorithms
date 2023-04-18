#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int last1=-1,last2=-1;
		bool ky=true;
		for(int i=1;i<=n;++i){
			int tmp;
			cin>>tmp;
			if(tmp%2){
				if(tmp<last1)ky=false;
				last1=tmp;
			}
			else{
				if(tmp<last2)ky=false;
				last2=tmp;
			}
		}
		if(ky)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	
	return 0;
}