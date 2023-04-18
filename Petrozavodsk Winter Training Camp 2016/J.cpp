#include<bits/stdc++.h>
using namespace std;
const int INF=2147483647;
struct edge{
	int from,to,nxt;
	char value;
}e[1000005];
int n,m,Head[500005],cnt,sonnum[500005],dp[500005],last[500005],last2[500005],son2[500005],son[500005],maxnum[500005],mmax[500005],llast[500005];
void add(int x,int y,char z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
char s[500005];
void dfs(int now,int pre){
	//dp[now]=maxnum[now]=sonnum[now]=last2[now]=son2[now]=mmax[now]=llast[now];
	last[now]=now;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		++sonnum[now];
		dfs(to,now);
		if(e[i].value==s[dp[to]+1]){
			if(dp[now]<dp[to]+1){
				mmax[now]=dp[now];
				llast[now]=last[now];
				dp[now]=dp[to]+1;
				last[now]=last[to];
				maxnum[now]=1;
				son[now]=to;
			}
			else if(dp[now]==dp[to]+1){
				++maxnum[now];
				son2[now]=to;
				last2[now]=last[to];
			}
			else;
		}
		else{
			if(dp[now]<dp[to]){
				mmax[now]=dp[now];
				llast[now]=last[now];
				dp[now]=dp[to];
				last[now]=last[to];
				maxnum[now]=1;
				son[now]=to;
			}
			else if(dp[now]==dp[to]){
				++maxnum[now];
				son2[now]=to;
				last2[now]=last[to];
			}
			else;
		}
	}
}
void dfsss(int now,int pre){
	//dp[now]=maxnum[now]=sonnum[now]=last2[now]=son2[now]=mmax[now]=llast[now];
	last[now]=now;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		++sonnum[now];
		dfsss(to,now);
		if(e[i].value==s[m-dp[to]]){
			if(dp[now]<dp[to]+1){
				mmax[now]=dp[now];
				llast[now]=last[now];
				dp[now]=dp[to]+1;
				last[now]=last[to];
				maxnum[now]=1;
				son[now]=to;
			}
			else if(dp[now]==dp[to]+1){
				++maxnum[now];
				son2[now]=to;
				last2[now]=last[to];
			}
			else;
		}
		else{
			if(dp[now]<dp[to]){
				mmax[now]=dp[now];
				llast[now]=last[now];
				dp[now]=dp[to];
				last[now]=last[to];
				maxnum[now]=1;
				son[now]=to;
			}
			else if(dp[now]==dp[to]){
				++maxnum[now];
				son2[now]=to;
				last2[now]=last[to];
			}
			else;
		}
	}
}
void dfss(int now,int pre){
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		if(son[now]==to&&maxnum[now]>1){
			swap(son2[now],son[now]);
			swap(last2[now],last[now]);
		}
			if(son[now]!=to){
				if(e[i].value==s[dp[now]+1]){
					if(dp[to]<dp[now]+1){
						mmax[to]=dp[to];
						llast[to]=last[to];
						dp[to]=dp[now]+1;
						son[to]=now;
						maxnum[to]=1;
						last[to]=last[now];
					}
					else if(dp[to]==dp[now]+1){
						++maxnum[to];
						son2[to]=now;
						last2[to]=last[now];
					}
					else;
				}
				else{
					if(dp[to]<dp[now]){
						mmax[to]=dp[to];
						llast[to]=last[to];
						dp[to]=dp[now];
						son[to]=now;
						maxnum[to]=1;
						last[to]=last[now];
					}
					else if(dp[to]==dp[now]){
						++maxnum[to];
						son2[to]=now;
						last2[to]=last[now];
					}
					else;
				}
			}
			else{
				if(e[i].value==s[mmax[now]+1]){
					if(dp[to]<mmax[now]+1){
						mmax[to]=dp[to];
						llast[to]=last[to];
						dp[to]=mmax[now]+1;
						son[to]=now;
						maxnum[to]=1;
						last[to]=llast[now];
					}
					else if(dp[to]==mmax[now]+1){
						++maxnum[to];
						son2[to]=now;
						last2[to]=llast[now];
					}
					else;
				}
				else{
					if(dp[to]<mmax[now]){
						mmax[to]=dp[to];
						llast[to]=last[to];
						dp[to]=mmax[now];
						son[to]=now;
						maxnum[to]=1;
						last[to]=llast[now];
					}
					else if(dp[to]==mmax[now]){
						++maxnum[to];
						son2[to]=now;
						last2[to]=llast[now];
					}
					else;
				}
			}
		dfss(to,now);
	}
}
void dfssss(int now,int pre){
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		if(son[now]==to&&maxnum[now]>1){
			swap(son2[now],son[now]);
			swap(last2[now],last[now]);
		}
			if(son[now]!=to){
				if(e[i].value==s[m-dp[now]]){
					if(dp[to]<dp[now]+1){
						mmax[to]=dp[to];
						llast[to]=last[to];
						dp[to]=dp[now]+1;
						son[to]=now;
						maxnum[to]=1;
						last[to]=last[now];
					}
					else if(dp[to]==dp[now]+1){
						++maxnum[to];
						son2[to]=now;
						last2[to]=last[now];
					}
					else;
				}
				else{
					if(dp[to]<dp[now]){
						mmax[to]=dp[to];
						llast[to]=last[to];
						dp[to]=dp[now];
						son[to]=now;
						maxnum[to]=1;
						last[to]=last[now];
					}
					else if(dp[to]==dp[now]){
						++maxnum[to];
						son2[to]=now;
						last2[to]=last[now];
					}
					else;
				}
			}
			else{
				if(e[i].value==s[m-mmax[now]]){
					if(dp[to]<mmax[now]+1){
						mmax[to]=dp[to];
						llast[to]=last[to];
						dp[to]=mmax[now]+1;
						son[to]=now;
						maxnum[to]=1;
						last[to]=llast[now];
					}
					else if(dp[to]==mmax[now]+1){
						++maxnum[to];
						son2[to]=now;
						last2[to]=llast[now];
					}
					else;
				}
				else{
					if(dp[to]<mmax[now]){
						mmax[to]=dp[to];
						llast[to]=last[to];
						dp[to]=mmax[now];
						son[to]=now;
						maxnum[to]=1;
						last[to]=llast[now];
					}
					else if(dp[to]==mmax[now]){
						++maxnum[to];
						son2[to]=now;
						last2[to]=llast[now];
					}
					else;
				}
			}
		dfssss(to,now);
	}
}
int main(){
	//cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<n;++i){
		int x,y;
		char t;
		cin>>x>>y>>t;
		add(x,y,t);
		add(y,x,t);
	} 
	cin>>(s+1);
	dfs(1,0);
	dfss(1,0);
	for(int i=1;i<=n;++i){
		if(dp[i]==m){
			cout<<last[i]<<" "<<i<<endl;
			return 0;
		}
	}
	memset(dp,0,sizeof(dp));
	memset(maxnum,0,sizeof(maxnum));
	memset(sonnum,0,sizeof(sonnum));
	memset(last2,0,sizeof(last2));
	memset(son2,0,sizeof(son2));
	memset(mmax,0,sizeof(mmax));
	memset(llast,0,sizeof(llast));
	//dp[now]=maxnum[now]=sonnum[now]=last2[now]=son2[now]=mmax[now]=llast[now];
	dfsss(1,0);
	dfssss(1,0);
	for(int i=1;i<=n;++i){
		if(dp[i]==m){
			cout<<i<<" "<<last[i]<<endl;
			return 0;
		}
	}
	cout<<"-1 -1"<<endl;
	return 0;
}
