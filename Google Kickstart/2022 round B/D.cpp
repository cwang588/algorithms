#include<bits/stdc++.h>
using namespace std;
char a[205][205];
bool usd[405][405];
int n,m;
int mov[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char c[]={'S','E','N','W'};
string ans;
void dfs(int x,int y,int last,int pos){
	usd[x][y]=true;
	int re=0;
	for(int i=last-1;i<=last+1;++i){
		int id=(i+4)%4;
		int tox=x+mov[id][0],toy=y+mov[id][1];
		if(tox<=0||tox>n||toy<=0||toy>m||usd[tox][toy])continue;
		ans+=c[id];
		if(pos==1){
			if(c[id]=='W')dfs(tox,toy,id,2),pos=3;	
			if(c[id]=='S')ans+=c[id],dfs(tox,toy,id,1),pos=4;	
			if(c[id]=='E')ans+=c[id],dfs(tox,toy,id,1),pos=4;	
			if(c[id]=='N')dfs(tox,toy,id,3),pos=2;	
		}else if(pos==2){
			if(c[id]=='W')ans+=c[id],dfs(tox,toy,id,2),pos=3;	
			if(c[id]=='S')ans+=c[id],dfs(tox,toy,id,2),pos=3;	
			if(c[id]=='E')dfs(tox,toy,id,1),pos=4;	
			if(c[id]=='N')dfs(tox,toy,id,4),pos=1;	
		}else if(pos==3){
			if(c[id]=='W')dfs(tox,toy,id,4),pos=1;	
			if(c[id]=='S')dfs(tox,toy,id,1),pos=4;	
			if(c[id]=='E')ans+=c[id],dfs(tox,toy,id,3),pos=2;	
			if(c[id]=='N')ans+=c[id],dfs(tox,toy,id,3),pos=2;	
		}else{
			if(c[id]=='W')ans+=c[id],dfs(tox,toy,id,4),pos=1;	
			if(c[id]=='S')dfs(tox,toy,id,2),pos=3;	
			if(c[id]=='E')dfs(tox,toy,id,3),pos=2;	
			if(c[id]=='N')ans+=c[id],dfs(tox,toy,id,4),pos=1;	
		}
	}
	if(x!=1||y!=1){
		if(pos==1){
			if(last==0)ans+="SEWW";
			if(last==1)ans+="SEE";
			if(last==2)ans+="ESS";
			if(last==3)ans+='W';
		}
	}
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		ans="";
		memset(usd,0,sizeof(usd));
		cin>>n>>m;		
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>a[i][j];
				usd[i][j]=true;
			}
		}
		dfs(1,1,1,1);
		ans+='W';
		bool ky=true;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]=='*'&&!usd[i][j]){
					ky=false;
					break;
				}
			}
			if(!ky)break;
		}
		printf("Case #%d: ",Case);
		if(!ky)printf("IMPOSSIBLE\n");
		else cout<<ans<<"\n";
	}
	
	return 0;
}