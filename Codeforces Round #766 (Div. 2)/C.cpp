#include<bits/stdc++.h>
using namespace std;
int cnt[100005];
vector<pair<int,int> >to[100005];
int ans[100005];
bool usd[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cnt[i]=0,usd[i]=false,to[i].clear();
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			++cnt[x],++cnt[y];
			to[x].push_back(make_pair(y,i));
			to[y].push_back(make_pair(x,i));
		}
		bool ky=true;
		for(int i=1;i<=n;++i){
			if(cnt[i]>2){
				ky=false;
				break;
			}
		}
		if(!ky){
			cout<<"-1\n";
			continue;
		}
		for(int i=1;i<=n;++i){
			if(to[i].size()==1){
				int now=i,value=3;
				ans[to[now][0].second]=2;
				usd[now]=true;
				while(true){
					if(usd[to[now][0].first]){
						if(to[now].size()==1)break;
						ans[to[now][1].second]=value;
						value=5-value;
						now=to[now][1].first;
					}
					else{
						ans[to[now][0].second]=value;
						value=5-value;
						now=to[now][0].first;
					}
					usd[now]=true;
				}
				break;
			}
		}
		for(int i=1;i<n;++i)cout<<ans[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}