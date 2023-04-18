#include<bits/stdc++.h>
using namespace std;
map<string,int>id;
int idcnt,n,m;
char type[25],t;
vector<int>member[55];
double dp[2<<15][2][55][18];
int getcnt(int state,int id){
	int re=0;
	for(const auto &x:member[id]){
		if((state&(1<<(x-1)))==0)++re;
	}
	return re;
}
double dfs(int state,int now,int card,int num){
	if(dp[state][now][card][num]!=-1)return dp[state][now][card][num];
	bool allr=true,allb=true;
	for(int i=0;i<n;++i){
		if(((1<<i)&state)==0){
			if(type[i+1]=='B')allb=false;
			if(type[i+1]=='R')allr=false;
			continue;
		}
		if(type[i+1]=='A'){
			if(!now)dp[state][now][card][num]=0;
			else dp[state][now][card][num]=1;
			return dp[state][now][card][num];
		}
	}
	if(allb){
		if(t=='B')dp[state][now][card][num]=1;
		else dp[state][now][card][num]=0;
		return dp[state][now][card][num];
	}
	if(allr){
		if(t=='R')dp[state][now][card][num]=1;
		else dp[state][now][card][num]=0;
		return dp[state][now][card][num];
	}
	if(card&&!num){
		dp[state][now][card][num]=dfs(state,1-now,0,0);
		return dp[state][now][card][num];
	}
	if(!card){
		if(now==0){
			dp[state][now][card][num]=0;
			for(int i=1;i<=m;++i){
				int curcnt=getcnt(state,i);
				if(!curcnt)continue;
				for(int j=1;j<=curcnt;++j){
					dp[state][now][card][num]=max(dp[state][now][card][num],dfs(state,now,i,j));
				}
			}
		}else{
			dp[state][now][card][num]=1;
			for(int i=1;i<=m;++i){
				int curcnt=getcnt(state,i);
				if(!curcnt)continue;
				for(int j=1;j<=curcnt;++j){
					dp[state][now][card][num]=min(dp[state][now][card][num],dfs(state,now,i,j));
				}
			}
		}
	}else{
		dp[state][now][card][num]=0;
		int curcnt=getcnt(state,card);
		for(const auto &nxt:member[card]){
			if((1<<(nxt-1))&state)continue;
			if(type[nxt]=='B'){
				if(!now){
					if(t=='B')dp[state][now][card][num]+=dfs(state|(1<<(nxt-1)),now,card,num-1);
					else dp[state][now][card][num]+=dfs(state|(1<<(nxt-1)),1-now,0,0);
				}else{
					if(t=='R')dp[state][now][card][num]+=dfs(state|(1<<(nxt-1)),now,card,num-1);
					else dp[state][now][card][num]+=dfs(state|(1<<(nxt-1)),1-now,0,0);
				}
			}else if(type[nxt]=='R'){
				if(!now){
					if(t=='R')dp[state][now][card][num]+=dfs(state|(1<<(nxt-1)),now,card,num-1);
					else dp[state][now][card][num]+=dfs(state|(1<<(nxt-1)),1-now,0,0);
				}else{
					if(t=='B')dp[state][now][card][num]+=dfs(state|(1<<(nxt-1)),now,card,num-1);
					else dp[state][now][card][num]+=dfs(state|(1<<(nxt-1)),1-now,0,0);
				}
			}
			else if(type[nxt]=='A')dp[state][now][card][num]+=dfs(state|(1<<(nxt-1)),now,0,0);
			else dp[state][now][card][num]+=dfs(state|(1<<(nxt-1)),1-now,0,0);
		}
		dp[state][now][card][num]/=curcnt;
	}
	return dp[state][now][card][num];
}
int main(){
	cin>>n>>t;
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		if(!id[s])id[s]=++idcnt;
	}
	for(int i=1;i<=n;++i)cin>>type[i];
	cin>>m;
	for(int i=1;i<=m;++i){
		int num;
		cin>>num;
		while(num--){
			string name;
			cin>>name;
			member[i].push_back(id[name]);
		}
	}
	for(int i=0;i<(1<<n);++i){
		for(int j=0;j<=1;++j){
			for(int k=0;k<=m;++k){
				for(int o=0;o<=n;++o)dp[i][j][k][o]=-1;
			}
		}
	}
	double ans=dfs(0,0,0,0);
	printf("%.12f\n",ans);
	return 0;
}