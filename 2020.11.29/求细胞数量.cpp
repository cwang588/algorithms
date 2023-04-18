#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int> >q;
char a[105][105];
bool usd[105][105];
int to[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int main(){
	int n,m; 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>a[i][j];
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]!='0'&&!usd[i][j]){
				++cnt;
				q.push(make_pair(i,j));
				usd[i][j]=true;
				while(!q.empty()){
					int nowx=q.front().first,nowy=q.front().second;
					q.pop();
					for(int k=0;k<=3;++k){
						int tox=nowx+to[k][0],toy=nowy+to[k][1];
						if(tox<=0||tox>n||toy<=0||toy>m||a[tox][toy]=='0'||usd[tox][toy])continue;
						q.push(make_pair(tox,toy));
						usd[tox][toy]=true;
					}
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
