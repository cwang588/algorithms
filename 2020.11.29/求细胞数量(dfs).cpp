#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int n,m; 
bool usd[105][105];
int to[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int x,int y){
	usd[x][y]=true;
	for(int i=0;i<=3;++i){
		int tox=x+to[i][0],toy=y+to[i][1];
		if(tox<=0||tox>n||toy<=0||toy>m||a[tox][toy]=='0'||usd[tox][toy])continue;
		dfs(tox,toy);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>a[i][j];
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]!='0'&&!usd[i][j])++cnt,dfs(i,j);
		}
	}
	printf("%d\n",cnt);
	return 0;
}
