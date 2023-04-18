#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000;
pair<int,int>arc[MAXN];
vector<int>point[MAXN<<1],polygon[MAXN];
int pl[MAXN],pr[MAXN];
int main(){
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int s,t;
		cin>>s>>t;
		arc[i]=make_pair(s,t);
	}
	for(int i=1;i<=n;++i){
		int num;
		cin>>num;
		while(num--){
			int tmp;
			cin>>tmp;
			point[i].push_back(tmp);
		}
	}
	for(int i=1;i<=m;++i){
		if(pl[i]&&pr[i])continue;
		if(!pl[i]){
			++cnt;
			polygon[cnt].push_back(i);
			pl[i]=cnt;
			int n0=arc[i].first,nc=arc[i].second;
			int sc=i;
			while(n0!=nc){
				for(int j=0;j<point[nc].size();++j){
					if(point[nc][j]==sc){
						sc=point[nc][(j+1)%point[nc].size()];
						break;
					}
				}
				polygon[cnt].push_back(sc);
				if(nc==arc[sc].first){
					pl[sc]=cnt;
					nc=arc[sc].second;
				}
				else{
					pr[sc]=cnt;
					nc=arc[sc].first;
				}
			}
		}
		else{
			++cnt;
			polygon[cnt].push_back(i);
			pr[i]=cnt;
			int n0=arc[i].second,nc=arc[i].first;
			int sc=i;
			while(n0!=nc){
				for(int j=0;j<point[nc].size();++j){
					if(point[nc][j]==sc){
						sc=point[nc][(j+1)%point[nc].size()];
						break;
					}
				}
				polygon[cnt].push_back(sc);
				if(nc==arc[sc].first){
					pl[sc]=cnt;
					nc=arc[sc].second;
				}
				else{
					pr[sc]=cnt;
					nc=arc[sc].first;
				}
			}
		}
	}
	for(int i=1;i<=m;++i)cout<<i<<" "<<pl[i]<<" "<<pr[i]<<endl;
	return 0;
}
