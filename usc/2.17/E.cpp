#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int col[1005][1005],cnt,n,m;
int mov[][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y){
	col[x][y]=cnt;
	for(int i=0;i<4;++i){
		int tox=x+mov[i][0],toy=y+mov[i][1];
		if(tox<1||tox>n||toy<1||toy>m||col[tox][toy]||a[tox][toy]!=a[x][y])continue;
		dfs(tox,toy);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)cin>>a[i][j];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(col[i][j])continue;
			++cnt;
			dfs(i,j);
		}
	}
	int q;
	cin>>q;
	while(q--){
		int xx1,yy1,xx2,yy2;
		cin>>xx1>>yy1>>xx2>>yy2;
		if(col[xx1][yy1]!=col[xx2][yy2])cout<<"neither\n";
		else{
			if(a[xx1][yy1]=='0')cout<<"binary\n";
			else cout<<"decimal\n";
		}
	}
	return 0;
}