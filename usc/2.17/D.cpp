#include<bits/stdc++.h>
using namespace std;
vector<int>to[1005],val[1005];
int dis[35][1005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;++i){
			to[i].clear(),val[i].clear();
			int m;
			cin>>m;
			while(m--){
				int x,y;
				cin>>x>>y;
				to[i].push_back(x),val[i].push_back(y);
			}
		}
		int m;
		cin>>m;
		while(m--){
			int x,y,k;
			cin>>x>>y>>k;
			--k;
			for(int i=0;i<n;++i)dis[0][i]=1e9;
			dis[0][x]=0;
			for(int i=1;i<=k;++i){
				for(int j=0;j<n;++j)dis[i][j]=dis[i-1][j];
				for(int j=0;j<n;++j){
					for(int o=0;o<to[j].size();++o){
						dis[i][to[j][o]]=min(dis[i-1][j]+val[j][o],dis[i][to[j][o]]);
					}
				}
			}
			if(dis[k][y]<1e8)cout<<dis[k][y]<<"\n";
			else cout<<"-1\n";
		}
	}
	
	
	return 0;
}