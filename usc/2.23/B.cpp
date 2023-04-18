#include<bits/stdc++.h>
using namespace std;
char a[505][505];
int cnt,num[250005],id[505][505];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			if(a[i][j]=='#')id[i][j]=++cnt;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
	}
	return 0;
}