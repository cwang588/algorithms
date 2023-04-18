#include<bits/stdc++.h>
using namespace std;
int getid(int x,int y,int m){
	return x*m+y;
}
pair<int,vector<pair<int,int> > >get_min_distance(vector<vector<int> >a){
	int mov[][2]={{1,0},{0,1},{-1,0},{0,-1}};
	int n=a.size(),m=a[0].size();
	vector<bool>usd(n*m);
	vector<pair<int,int> >pre(n*m);
	vector<int>dis(n*m);
	queue<pair<int,int> >q;
	q.push(make_pair(0,0));
	usd[0]=true;
	while(!q.empty()){
		auto now=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			int tox=now.first+mov[i][0],toy=now.second+mov[i][1];
			int nowid=getid(tox,toy,m);
			if(tox>=0&&tox<n&&toy>=0&&toy<m&&!usd[nowid]){
				usd[nowid]=true;
				dis[nowid]=dis[getid(now.first,now.second,m)]+1;
				pre[nowid]=now;
				q.push(make_pair(tox,toy));
			}
		}
	}
	pair<int,vector<pair<int,int> > >ans;
	ans.first=dis[getid(n-1,m-1,m)];
	vector<pair<int,int> >road;
	road.push_back(make_pair(n-1,m-1));
	int pos=getid(n-1,m-1,m);
	while(pos){
		road.push_back(pre[pos]);
		pos=getid(pre[pos].first,pre[pos].second,m);
	}
	ans.second=road;
	return ans;
}
int main(){
	
	
	return 0;

}