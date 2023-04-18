#include<bits/stdc++.h>
using namespace std;
char a[55][55];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,x,y;
		cin>>n>>m>>x>>y;
		bool ky=false;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>a[i][j];
				if(a[i][j]=='B')ky=true;
			}
		}
		if(!ky){
			cout<<"-1\n";
			continue;
		}
		if(a[x][y]=='B')cout<<"0\n";
		else{
			bool usd=false;
			for(int i=1;i<=n;++i){
				if(a[i][y]=='B'){
					cout<<"1\n";
					usd=true;
					break;
				}
			}
			if(usd)continue;
			for(int i=1;i<=m;++i){
				if(a[x][i]=='B'){
					cout<<"1\n";
					usd=true;
					break;
				}
			}
			if(usd)continue;
			cout<<"2\n";
		}
	}
	
	
	return 0;
}