#include<bits/stdc++.h>
using namespace std;
int ans,col[50][50],n,m;
bool check(int n,int m){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			for(int k=i+1;k<=n;++k)
				for(int o=j+1;o<=m;++o){
					if(col[i][j]==col[i][o]&&col[k][j]==col[k][o])return false;
					if(col[i][j]==col[k][j]&&col[i][o]==col[k][o])return false;
				}
	return true;
}
void dfs(int x,int y){
	if(x>n){
		++ans;
		return;
	}
	for(int i=1;i<=3;++i){
		col[x][y]=i;
		if(!check(x,y))continue;
		if(y==m)dfs(x+1,1);
		else dfs(x,y+1);
	}
}
int main(){
	for(int i=1;i<=7;++i){
		printf("{");
		for(int j=1;j<=7;++j){
			ans=0,n=i,m=j;
			dfs(1,1);
			printf("%d,",ans);
		}
		printf("},\n");
	}
	return 0;
}
