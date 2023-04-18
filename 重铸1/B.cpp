#include<bits/stdc++.h>
using namespace std;
long long value[500005];
struct op{
	int pos,id,num;
};
vector<op>v[500005];
long long ans[500005];
bool cmp(op x,op y){
	return x.pos<y.pos;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i)cin>>value[i];
	long long tot=0;
	for(int i=1;i<=n;++i){
		int l,r,k;
		cin>>l>>r>>k;
		for(int j=1;j<=k;++j){
			int tmp;
			cin>>tmp;
			v[tmp].push_back(op{l,i,1});
			v[tmp].push_back(op{r+1,i,-1});
		//	tot+=value[tmp]*(r-l+1);
		}
	}
//	for(int i=1;i<=n;++i)ans[i]=tot;
	set<int>s;
	for(int i=1;i<=m;++i){
		s.clear();
		sort(v[i].begin(),v[i].end(),cmp);
		for(int j=0;j<v[i].size();++j){
			if(s.size()==1){
				int yao=*s.begin();
				ans[yao]-=(v[i][j].pos-v[i][j-1].pos)*value[i];	
			}
			if(s.size()){
				tot+=(v[i][j].pos-v[i][j-1].pos)*value[i];
			}
			if(v[i][j].num==1)s.insert(v[i][j].id);
			else s.erase(v[i][j].id);
		}
	}
	for(int i=1;i<=n;++i)cout<<tot+ans[i]<<" ";
	return 0;
}
