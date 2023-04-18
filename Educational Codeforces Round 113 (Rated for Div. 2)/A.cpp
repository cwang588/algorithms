#include<bits/stdc++.h>
using namespace std;
char s[55];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n>>(s+1);
		bool ky=false;
		for(int i=2;i<=n;++i){
			if(s[i]!=s[i-1]){
				ky=true;
				cout<<i-1<<" "<<i<<"\n";
				break;
			}
		}
		if(!ky)cout<<"-1 -1\n";
	} 
	
	return 0;
}
