#include<bits/stdc++.h>
using namespace std;
int dis[505][505];
vector<pair<int,int> >v;
map<pair<int,int>,bool>mm;
void add(int x,int y){
	pair<int,int>now=make_pair(x,y);
	if(mm[now])return;
	mm[now]=true;
	v.push_back()
} 
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)dis[i][j]=19260817;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		dis[x][y]=1;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(dis[i][j]==1&&dis[j][i]==1){
				add(i,j);
				add(j,i);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(dis[i][j]==1&&dis[j][k]==1&&dis[k][i]==1){
					add(i,j);
					add(j,k);
					add(k,i);
				}
			}
		}
	}
	
	return 0;
}
