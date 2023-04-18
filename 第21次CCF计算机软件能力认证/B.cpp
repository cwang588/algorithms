#include<bits/stdc++.h>
using namespace std;
int x[10005],y[10005],cnt[5];
map<pair<int,int>,bool>m;
int mov[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool judge(int now){
	int nowx=x[now],nowy=y[now];
	for(int i=0;i<4;++i){
		int tox=nowx+mov[i][0],toy=nowy+mov[i][1];
		if(!m[make_pair(tox,toy)])return false;
	}
	return true;
}
void calc(int now){
	int nowx=x[now],nowy=y[now],tmp=0;
	for(int i=-1;i<=1;i+=2){
		for(int j=-1;j<=1;j+=2){
			if(m[make_pair(nowx+i,nowy+j)])++tmp;
		}
	}
	++cnt[tmp];
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>x[i]>>y[i],m[make_pair(x[i],y[i])]=true;
	for(int i=1;i<=n;++i){
		if(judge(i))calc(i);
	}
	for(int i=0;i<=4;++i)cout<<cnt[i]<<endl;
	return 0;
}
