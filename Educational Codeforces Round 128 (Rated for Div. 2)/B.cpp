#include<bits/stdc++.h>
using namespace std;
char a[16][16];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)cin>>a[i][j];
		}
		int x=10,y=10;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]=='R'){
					x=min(x,i);
					y=min(y,j);
				}
			}
		}
		bool ky=false;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]=='R'){
					if(i<=x&&j<=y)ky=true;
				}
			}
		}
		if(ky)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	
	return 0;
}