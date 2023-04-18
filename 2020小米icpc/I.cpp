#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int type[1005][1005];
bool usd[1005][1005];
stack<pair<int,int> >s;
int n,m;
void dfs(int x,int y){
	usd[x][y]=true;
	s.push(make_pair(x,y));
	int tox=x,toy=y;
	if(a[x][y]=='W')--tox;	
	else if(a[x][y]=='S')++tox;	
	else if(a[x][y]=='A')--toy;	
	else ++toy;
	if(tox<1||tox>n||toy<1||toy>m)type[x][y]=1;
	else{
		if(!type[tox][toy]){
			if(!usd[tox][toy])dfs(tox,toy);
			else{
				pair<int,int>now;
				do{
					now=s.top();
					type[now.first][now.second]=2;
					s.pop();
				}while(now.first!=tox||now.second!=toy);
			}
		}
		type[x][y]=type[tox][toy]; 
	}	
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>a[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!type[i][j])
				dfs(i,j);
	int cnt=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(type[i][j]==1)
				++cnt;
	printf("%d\n",cnt);
	return 0;
}
