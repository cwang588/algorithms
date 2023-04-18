#include<bits/stdc++.h>
using namespace std;
char a[15][15];
int ans,num;
int mov[][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool inbound(int x,int y){
	return !(x<1||x>5||y<1||y>9);
}
void dfs(int now){
	int cnt=0;
	for(int i=1;i<=5;++i){
		for(int j=1;j<=9;++j){
			if(a[i][j]=='o'){
				++cnt;
				for(int k=0;k<4;++k){
					int x=i+mov[k][0],y=j+mov[k][1],tox=x+mov[k][0],toy=y+mov[k][1];
					if(inbound(x,y)&&inbound(tox,toy)&&a[x][y]=='o'&&a[tox][toy]=='.'){
						a[i][j]=a[x][y]='.',a[tox][toy]='o';
						dfs(now+1);
						a[i][j]=a[x][y]='o',a[tox][toy]='.';
					}
				}
			}
		}
	}
	if(cnt<ans){
		ans=cnt;
		num=now;
	}else if(cnt==ans){
		num=min(now,num);
	}else;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=1;i<=5;++i){
			for(int j=1;j<=9;++j)cin>>a[i][j];
		}
		ans=num=2147483647;
		dfs(0);
		cout<<ans<<" "<<num<<"\n";
	}
	
	
	return 0;
}