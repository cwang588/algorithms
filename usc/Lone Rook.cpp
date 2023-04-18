#include<bits/stdc++.h>
using namespace std;
bool usd[2005];
char a[755][755];
int n,m,cnt[755][755];
int mov[][2]={{2,-1},{2,1},{1,-2},{1,2},{-1,-2},{-1,2},{-2,-1},{-2,1}};
bool inbound(int x,int y){
	return !(x<1||x>n||y<1||y>n);
}
int main(){
	cin>>n>>m;
	int x,y,tx,ty;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			if(a[i][j]=='K'){
				for(int k=0;k<8;++k){
					int tox=i+mov[k][0],toy=j+mov[k][1];
					if(inbound(tox,toy))++cnt[tox][toy];
				}
			}else if(a[i][j]=='R'){
				x=i,y=j;
			}else if(a[i][j]=='T'){
				tx=i,ty=j;
			}else;
		}
	}
	queue<int>q;
	q.push(x),q.push(y+n);
	usd[x]=usd[y+n]=true;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now<=n){
			for(int i=1;i<=m;++i){
				if(!cnt[now][i]&&!usd[i+n]){
					usd[i+n]=true;
					q.push(i+n);
					if(a[now][i]=='K'){
						for(int j=0;j<8;++j){
							int tox=now+mov[j][0],toy=i+mov[j][1];
							if(!inbound(tox,toy))continue;
							--cnt[tox][toy];
							if(!cnt[tox][toy]){
								if(!(usd[tox]^usd[toy]))continue;
								if(usd[tox]){
									q.push(toy+n);
									usd[toy+n]=true;
								}else{
									q.push(tox);
									usd[tox]=true;
								}
							}
						}
					}
				}
			}	
		}else{
			for(int i=1;i<=n;++i){
				if(!cnt[i][now-n]&&!usd[i]){
					usd[i]=true;
					q.push(i);
					if(a[i][now-n]=='K'){
						for(int j=0;j<8;++j){
							int tox=i+mov[j][0],toy=now-n+mov[j][1];
							if(!inbound(tox,toy))continue;
							--cnt[tox][toy];
							if(!cnt[tox][toy]){
								if(!(usd[tox]^usd[toy]))continue;
								if(usd[tox]){
									q.push(toy+n);
									usd[toy+n]=true;
								}else{
									q.push(tox);
									usd[tox]=true;
								}
							}
						}
					}
				}
			}	
		}
	}
	if(!cnt[tx][ty]&&usd[tx]&&usd[ty+n])cout<<"yes\n";
	else cout<<"no\n";
	return 0;
}