#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(m>(n+1)/2){
			cout<<"-1\n";
			continue;		
  		}
  		for(int i=1;i<=n;++i){
  			for(int j=1;j<=n;++j){
  				if(i==j&&i%2&&(i+1)/2<=m)cout<<"R";
  				else cout<<".";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}