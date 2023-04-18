#include<bits/stdc++.h>
using namespace std;
int f[5005][5005],g[5005][5005],h[5005],job[5005],F[5005][5005],G[5005][5005];
set<pair<int,int> >to_apply[5005];
vector<int>Apply[5005];
int main(){
	int n,seed;
	cin>>n>>seed;
	srand(seed);
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++)F[i][j]=j;
	    random_shuffle(F[i]+1,F[i]+1+n);
	}
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++)G[i][j]=j;
	    random_shuffle(G[i]+1,G[i]+1+n);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			f[i][F[i][j]]=j;
			g[i][G[i][j]]=j;
		}
	}
//	delete []F;
//	delete []G;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)to_apply[i].insert(make_pair(f[i][j],j));
	}
	int cnt=0;
	while(cnt<n){
		for(int i=1;i<=n;++i){
			if(job[i])continue;
			auto now=*(to_apply[i].begin());
			Apply[now.second].push_back(i);
		}
		for(int i=1;i<=n;++i){
			if(!Apply[i].size())continue;
			int now=n+1,pos;
			for(auto x:Apply[i]){
				if(g[i][x]<now){
					now=g[i][x];
					pos=x;
				}
			}
			for(auto x:Apply[i]){
				if(x!=pos){
					to_apply[x].erase(make_pair(f[x][i],i));
				}
			}
			if(!h[i]){
				h[i]=pos;
				job[pos]=i;
				++cnt;
			}
			else{
				if(g[i][h[i]]<g[i][pos]){
					to_apply[pos].erase(make_pair(f[pos][i],i));
				}
				else{
					job[h[i]]=0;
					to_apply[h[i]].erase(make_pair(f[h[i]][i],i));
					job[pos]=i;
					h[i]=pos;
				}
			}
			Apply[i].clear();
		}
	}
	for(int i=1;i<=n;++i)cout<<h[i]<<" ";
	cout<<"\n";
	return 0;
}