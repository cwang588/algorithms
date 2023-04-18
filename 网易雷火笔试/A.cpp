#include<bits/stdc++.h>
using namespace std;
char a[15][15];
bool usd[150];
bool check(){
	for(int i=1;i<=6;++i){
		memset(usd,0,sizeof(usd));
		for(int j=1;j<=6;++j){
			if(usd[a[i][j]])return false;
			usd[a[i][j]]=true;
		}
	}
	for(int i=1;i<=6;++i){
		memset(usd,0,sizeof(usd));
		for(int j=1;j<=6;++j){
			if(usd[a[j][i]])return false;
			usd[a[j][i]]=true;
		}
	}
	for(int i=1;i<=6;i+=2){
		for(int j=0;j<=1;++j){
			memset(usd,0,sizeof(usd));
			for(int k=i;k<=i+1;++k){
				for(int o=j*3+1;o<=j*3+3;++o){
					if(usd[a[k][o]])return false;
					usd[a[k][o]]=true;
				}
			}
		}
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	int ans=0;
	while(n--){
		for(int i=1;i<=6;++i){
			for(int j=1;j<=6;++j)cin>>a[i][j];
		}
		if(check())++ans;
	}
	cout<<ans<<"\n";
	return 0;
}