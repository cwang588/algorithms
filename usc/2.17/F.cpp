#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int dis1[105][105],dis2[105][105][2],n,m,tx1,ty1,tx2,ty2;
int mov[][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool usd[105][105];
bool inbound(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
void bfs(int x,int y,int id){
	memset(usd,0,sizeof(usd));
	queue<pair<int,int>>q;
	q.push(make_pair(x,y));
	usd[x][y]=true;
	dis2[x][y][id]=0;
	while(!q.empty()){
		auto now=q.front();
		q.pop();
		int nowdis=dis2[now.first][now.second][id];
		queue<pair<int,int>>tmp;
		tmp.push(now);
		while(!tmp.empty()){
			auto tnow=tmp.front();
			tmp.pop();
			int x=tnow.first,y=tnow.second;
			for(int i=0;i<4;++i){
				int tox=x+mov[i][0],toy=y+mov[i][1];
				if(!inbound(tox,toy)||usd[tox][toy]||a[tox][toy]=='*')continue;
				usd[tox][toy]=true;
				if(a[tox][toy]!='#'){
					dis2[tox][toy][id]=nowdis;
					tmp.push(make_pair(tox,toy));
				}else{
					dis2[tox][toy][id]=nowdis+1;
					q.push(make_pair(tox,toy));	
				}
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(usd,0,sizeof(usd));
		memset(dis1,0,sizeof(dis1));
		tx1=ty1=tx2=ty2=0;
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>a[i][j];
				if(a[i][j]=='$'){
					if(!tx1){
						tx1=i,ty1=j;
					}else{
						tx2=i,ty2=j;
					}
				}
			}
		}
		queue<pair<int,int>>q;
		vector<pair<int,int>>to_push;
		for(int i=1;i<=n;++i){
			if(a[i][1]=='.'||a[i][1]=='$'){
				q.push(make_pair(i,1)),usd[i][1]=true;
			}else if(a[i][1]=='#'){
				to_push.push_back(make_pair(i,1)),usd[i][1]=true;
				dis1[i][1]=1;
			}else;
			if(a[i][m]=='.'||a[i][m]=='$'){
				q.push(make_pair(i,m)),usd[i][m]=true;
			}else if(a[i][m]=='#'){
				to_push.push_back(make_pair(i,m)),usd[i][m]=true;
				dis1[i][m]=1;	
			}else;
		}
		for(int i=2;i<m;++i){
			if(a[1][i]=='.'||a[1][i]=='$'){
				q.push(make_pair(1,i)),usd[1][i]=true;
			}else if(a[1][i]=='#'){
				to_push.push_back(make_pair(1,i)),usd[1][i]=true;
				dis1[1][i]=1;
			}else;
			if(a[n][i]=='.'||a[n][i]=='$'){
				q.push(make_pair(n,i)),usd[n][i]=true;
			}else if(a[n][i]=='#'){
				to_push.push_back(make_pair(n,i)),usd[n][i]=true;
				dis1[n][i]=1;	
			}else;
		}
		for(const auto x:to_push)q.push(x);
		while(!q.empty()){
			auto now=q.front();
			q.pop();
			int nowdis=dis1[now.first][now.second];
			queue<pair<int,int>>tmp;
			tmp.push(now);
			while(!tmp.empty()){
				auto tnow=tmp.front();
				tmp.pop();
				int x=tnow.first,y=tnow.second;
				for(int i=0;i<4;++i){
					int tox=x+mov[i][0],toy=y+mov[i][1];
					if(!inbound(tox,toy)||usd[tox][toy]||a[tox][toy]=='*')continue;
					usd[tox][toy]=true;
					if(a[tox][toy]!='#'){
						dis1[tox][toy]=nowdis;
						tmp.push(make_pair(tox,toy));
					}else{
						dis1[tox][toy]=nowdis+1;
						q.push(make_pair(tox,toy));	
					}
				}
			}
		}
		memset(dis2,0,sizeof(dis2));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)dis2[i][j][0]=dis2[i][j][1]=1e9;
		}
		int ans=2147483647;
		bfs(tx1,ty1,0);
		bfs(tx2,ty2,1);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]=='*')continue;
				else if(a[i][j]=='#')ans=min(ans,dis1[i][j]+dis2[i][j][0]+dis2[i][j][1]-2);
				else ans=min(ans,dis1[i][j]+dis2[i][j][0]+dis2[i][j][1]);
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}