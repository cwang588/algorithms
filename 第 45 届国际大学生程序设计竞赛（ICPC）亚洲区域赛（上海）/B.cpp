#include<bits/stdc++.h>
using namespace std;
char a[1005][1005],b[1005][1005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)cin>>a[i][j];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)cin>>b[i][j];
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]==b[i][j])++cnt;
		}
	}
	if(cnt*2>=n*m){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)printf("%c",a[i][j]);
			printf("\n");
		}
	}
	else{
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]=='X')printf(".");
				else printf("X");
			}
			printf("\n");
		}
	}
	return 0;
}
