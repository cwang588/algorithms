#include<bits/stdc++.h>
using namespace std;
bool usd1[15],usd2[15];
int x[15],y[15];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(usd1,0,sizeof(usd1));
		memset(usd2,0,sizeof(usd2));
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=m;++i){
			cin>>x[i]>>y[i];
			usd1[x[i]]=usd2[y[i]]=true;
		}
		bool ky=false;
		for(int i=1;i<=m;++i){
			for(int j=1;j<=n;++j){
				if(j==x[i])continue;
				if(!usd1[j])ky=true;
			}
			for(int j=1;j<=n;++j){
				if(j==y[i])continue;
				if(!usd2[j])ky=true;
			}
		}
		if(ky)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}