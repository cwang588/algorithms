#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int pos[1005][1005][4];
bool usd[1004][1005];
pair<pair<int,int>,pair<int,int> >calc(pair<int,int>now){
	int x=now.first,y=now.second;
	return make_pair(make_pair(x,pos[x][y][0]+pos[x][y][1]-y),make_pair(pos[x][y][2]+pos[x][y][3]-x,y));
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)cin>>a[i][j],usd[i][j]=false;
		}
		for(int i=1;i<=n;++i){
			pos[i][0][0]=0;
			for(int j=1;j<=m;++j){
				if(a[i][j]=='#')pos[i][j][0]=j;
				else pos[i][j][0]=pos[i][j-1][0];
			}
		}
		for(int i=1;i<=n;++i){
			pos[i][m+1][1]=m+1;
			for(int j=m;j>=1;--j){
				if(a[i][j]=='#')pos[i][j][1]=j;
				else pos[i][j][1]=pos[i][j+1][1];
			}
		}
		for(int j=1;j<=m;++j){
			pos[0][j][2]=0;
			for(int i=1;i<=n;++i){
				if(a[i][j]=='#')pos[i][j][2]=i;
				else pos[i][j][2]=pos[i-1][j][2];
			}
		}
		for(int j=1;j<=m;++j){
			pos[n+1][j][3]=n+1;
			for(int i=n;i>=1;--i){
				if(a[i][j]=='#')pos[i][j][3]=i;
				else pos[i][j][3]=pos[i+1][j][3];
			}
		}
		queue<pair<int,int> >q;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]>='A'&&a[i][j]<='Z'){
					usd[i][j]=true;
					q.push(make_pair(i,j));
				}
			}
		}
		int cnt=0;
		while(!q.empty()){
			auto now=q.front();
			q.pop();
			auto pos=calc(now);
			int nowx=pos.first.first,nowy=pos.first.second;
			if(!usd[nowx][nowy]&&a[nowx][nowy]!='#'){
				a[nowx][nowy]=a[now.first][now.second];
				usd[nowx][nowy]=true;
				q.push(make_pair(nowx,nowy));
				++cnt;
			}
			nowx=pos.second.first,nowy=pos.second.second;
			if(!usd[nowx][nowy]&&a[nowx][nowy]!='#'){
				a[nowx][nowy]=a[now.first][now.second];
				usd[nowx][nowy]=true;
				q.push(make_pair(nowx,nowy));
				++cnt;
			}
		}
		printf("Case #%d: %d\n",Case,cnt);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)cout<<a[i][j];
			cout<<"\n";
		}
	}
	
	
	return 0;
}