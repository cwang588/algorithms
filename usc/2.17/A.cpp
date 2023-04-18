#include<bits/stdc++.h>
using namespace std;
char a[105][105];
bool usd[105][105];
int dis[105][105];
int mov[][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int main(){
	int n,tx,ty;
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j]=='K'){
				tx=i,ty=j;
			}
		}
	}
	queue<pair<int,int> >q;
	q.push(make_pair(1,1));
	usd[1][1]=true;
	while(!q.empty()){
		auto now=q.front();
		q.pop();
		int x=now.first,y=now.second;
		for(int i=0;i<8;++i){
			int tox=x+mov[i][0],toy=y+mov[i][1];
			if(tox<1||tox>n||toy<1||toy>n||usd[tox][toy]||a[tox][toy]=='#')continue;
			usd[tox][toy]=true;
			dis[tox][toy]=dis[x][y]+1;
			q.push(make_pair(tox,toy));
		}
	}
	if(usd[tx][ty])cout<<dis[tx][ty]<<"\n";
	else cout<<"-1\n";
	return 0;
}