#include<bits/stdc++.h>
using namespace std;
int a[305][305];
bool usd[305][305];
int getid(int x,int y){
	return x*500+y;
}
int mov[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)cin>>a[i][j],usd[i][j]=false;
		}
		priority_queue<pair<int,int> >q;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)q.push(make_pair(a[i][j],getid(i,j)));
		}
		long long ans=0;
		while(!q.empty()){
			auto now=q.top();
			q.pop();
			int x=now.second/500,y=now.second%500;
			if(usd[x][y])continue;
			for(int i=0;i<4;++i){
				int tox=x+mov[i][0],toy=y+mov[i][1];
				if(tox<=0||tox>n||toy<=0||toy>m||usd[tox][toy])continue;
				ans+=max(0,a[x][y]-1-a[tox][toy]);
				a[tox][toy]=max(a[tox][toy],a[x][y]-1);
				q.push(make_pair(a[tox][toy],getid(tox,toy)));
			}
			usd[x][y]=true;
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}


	
	return 0;
}