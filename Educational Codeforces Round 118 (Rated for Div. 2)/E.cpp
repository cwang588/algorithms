#include<bits/stdc++.h>
using namespace std;
vector<char>a[1000006];
int num[1000006],n,m;
int getid(int x,int y){
	return (x-1)*m+y;
}
int mov[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool usd[1000006];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			a[i].clear();
			a[i].push_back(' ');	
			for(int j=1;j<=m;++j){
				char now;
				cin>>now;
				a[i].push_back(now);
				usd[getid(i,j)]=false;
			}
		}
		queue<pair<int,int> >q;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]=='L'){
					q.push(make_pair(i,j));
					num[getid(i,j)]=0;
					usd[getid(i,j)]=true;
					continue;
				}
				int cnt=0;
				for(int k=0;k<=3;++k){
					int tox=i+mov[k][0],toy=j+mov[k][1];
					if(tox<=0||tox>n||toy<=0||toy>m||a[tox][toy]=='#')continue;
					++cnt;
				}
				num[getid(i,j)]=cnt;
			}
		}
		while(!q.empty()){
			int nowx=q.front().first,nowy=q.front().second;
			q.pop();
			for(int i=0;i<=3;++i){
				int tox=nowx+mov[i][0],toy=nowy+mov[i][1];
				if(tox<=0||tox>n||toy<=0||toy>m||a[tox][toy]=='#'||usd[getid(tox,toy)])continue;
				--num[getid(tox,toy)];
				if(num[getid(tox,toy)]<=1){
					q.push(make_pair(tox,toy));
					num[getid(tox,toy)]=0;
					usd[getid(tox,toy)]=true;
				}	
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]=='L'||!usd[getid(i,j)])cout<<a[i][j];
				else cout<<"+";
			}
			cout<<"\n";
		}
	}
	return 0;
}