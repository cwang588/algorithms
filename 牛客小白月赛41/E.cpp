#include<bits/stdc++.h>
using namespace std;
char a[55][55];
bool usd[55][55][55];
struct point{
	int x,y,hp,ans;
};
int mov[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main(){
	int n,m,h;
	cin>>n>>m>>h;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)cin>>a[i][j];
	}
	queue<point>q;
	q.push(point{1,1,h});
	usd[1][1][h]=true;
	while(!q.empty()){
		int x=q.front().x,y=q.front().y,hp=q.front().hp,ans=q.front().ans;
		if(x==n&&y==m)return !printf("%d",ans);
		q.pop();
		for(int i=0;i<=3;++i){
			int tox=x+mov[i][0],toy=y+mov[i][1],tohp=hp;
			if(tox<=0||toy<=0||tox>n||toy>m||a[tox][toy]=='*')continue;
			if(a[tox][toy]!='.'){
				tohp-=a[tox][toy]-'0';
				if(tohp<=0)continue;
			}
			if(usd[tox][toy][tohp])continue;
			usd[tox][toy][tohp]=true;
			q.push(point{tox,toy,tohp,ans+1});
		}
	}
	printf("-1");
	return 0;
}