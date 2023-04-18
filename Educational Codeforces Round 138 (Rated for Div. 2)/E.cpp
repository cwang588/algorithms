#include<bits/stdc++.h>
using namespace std;
char a[400005];
int dp[400005],last[400005],n,m;
bool usd[400005];
int getid(int x,int y){
	if(x==0||y==0)return 0;
	return (x-1)*m+y;
}
int mov[][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool check(int x,int y){
	for(int i=0;i<4;++i){
		int tox=x+mov[i][0],toy=y+mov[i][1];
		if(tox<=0||tox>n||toy<=0||toy>m)continue;
		if(a[getid(tox,toy)]=='#')return false;
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		dp[0]=last[0]=usd[0]=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int id=getid(i,j);
				cin>>a[getid(i,j)];
				dp[id]=last[id]=usd[id]=0;
			}
		}
		for(int i=1;i<=m;++i){
			for(int j=1;j<=n;++j){
				int id=getid(j,i);
				if(!check(j,i))dp[id]=100000000;
				else{
					if(j==1){
						last[id]=1;
						dp[id]=dp[getid(j+1,i-1)];
					}
					else if(j==n){
						last[id]=-1;
						dp[id]=dp[getid(j-1,i-1)];
					}
					else{
						int now1=dp[getid(j+1,i-1)],now2=dp[getid(j-1,i-1)];
						if(now1<=now2){
							dp[id]=now1;
							last[id]=1;	
						}
						else{
							dp[id]=now2;
							last[id]=-1;
						}
					}
					if(a[id]=='.')++dp[id];
				}
			}
		}
		int Min=2147483647,pos;
		for(int i=1;i<=n;++i){
			if(Min>dp[getid(i,m)]){
				Min=dp[getid(i,m)];
				pos=i;
			}
		}
		if(Min>m){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		int nowpos=pos;
		for(int i=m;i>=1;--i){
			usd[getid(nowpos,i)]=true;
			nowpos+=last[getid(nowpos,i)];
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int id=getid(i,j);
				if(a[id]=='#'||usd[id])cout<<'#';
				else cout<<'.';
			}
			cout<<"\n";
		}
	}
	return 0;
}