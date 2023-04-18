#include<bits/stdc++.h>
using namespace std;
char a[155][155];
bool usd[144][144];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,q;
		cin>>n>>m>>q;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)cin>>a[i][j],usd[i][j]=false;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]=='.')continue;
				int ans=10000,re=0;
				for(int k=1;;++k){
					if(i-k<1||j-k<1||a[i-k][j-k]=='.')break;
					++re;
				}
				ans=min(ans,re);
				re=0;
				for(int k=1;;++k){
					if(i-k<1||j+k>m||a[i-k][j+k]=='.')break;
					++re;
				}
				ans=min(ans,re);
				if(ans>=q){
					for(int k=0;k<=ans;++k)usd[i-k][j-k]=usd[i-k][j+k]=true;
				}
			}
		}
		bool ky=true;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]=='*'&&!usd[i][j]){
					cout<<"NO\n";
					ky=false;
					break;
				}
			}
			if(!ky)break;
		}
		if(ky)cout<<"YES\n";
	}
	
	return 0;
}
