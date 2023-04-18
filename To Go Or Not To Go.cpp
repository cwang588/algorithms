#include<bits/stdc++.h>
using namespace std;
const long long inf=114514191981066666;
long long a[2005][2005],dis1[2005][2005],dis2[2050][2050];
int mov[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int main(){
	ios::sync_with_stdio(false);
	int n,m,w;
	cin>>n>>m>>w;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			dis1[i][j]=dis2[i][j]=inf;
		}
	}
	queue<pair<int,long long> >q;
	q.push(make_pair(1,0));
	dis1[1][1]=0;
	while(!q.empty()){
		int now=q.front().first;
		long long now_dis=q.front().second;
		q.pop();
		int nowx=now/m+1,nowy=now%m;
		if(!nowy)nowy=m,--nowx;
		for(int i=0;i<4;++i){
			int tox=nowx+mov[i][0],toy=nowy+mov[i][1];
			if(tox<=0||tox>n||toy<=0||toy>m||a[tox][toy]==-1||dis1[tox][toy]<inf)continue;
			q.push(make_pair((tox-1)*m+toy,now_dis+w));
			dis1[tox][toy]=now_dis+w;
		}
	}
	q.push(make_pair(n*m,0));
	dis2[n][m]=0;
	while(!q.empty()){
		int now=q.front().first;
		long long now_dis=q.front().second;
		q.pop();
		int nowx=now/m+1,nowy=now%m;
		if(!nowy)nowy=m,--nowx;
		for(int i=0;i<4;++i){
			int tox=nowx+mov[i][0],toy=nowy+mov[i][1];
			if(tox<=0||tox>n||toy<=0||toy>m||a[tox][toy]==-1||dis2[tox][toy]<inf)continue;
			q.push(make_pair((tox-1)*m+toy,now_dis+w));
			dis2[tox][toy]=now_dis+w;
		}
	}
	long long min1=inf,min2=inf;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]<=0)continue;
			min1=min(min1,dis1[i][j]+a[i][j]);
			min2=min(min2,dis2[i][j]+a[i][j]);	
		}
	}
	long long ans=min(min1+min2,dis1[n][m]);
	if(ans==inf)cout<<"-1\n";
	else cout<<ans<<endl;
	return 0;
}
