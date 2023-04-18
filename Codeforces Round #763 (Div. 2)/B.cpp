#include<bits/stdc++.h>
using namespace std;
vector<int>s[1005],e[1005];
void solve(int l,int r){
	if(l>r)return;
	if(l==r){
		cout<<l<<" "<<r<<" "<<l<<"\n";
		return;
	}
	int L=0,R=s[l].size();
	while(L<R-1){
		int m=(L+R)>>1;
		if(s[l][m]<r)L=m;
		else R=m;
	}
	if(s[l][L]<r){
		cout<<l<<" "<<r<<" "<<s[l][L]+1<<"\n";
		solve(l,s[l][L]);
		solve(s[l][L]+2,r);
		return;
	}
	L=-1,R=e[r].size()-1;
	while(L<R-1){
		int m=(L+R)>>1;
		if(e[r][m]>l)R=m;
		else L=m;
	}
	cout<<l<<" "<<r<<" "<<e[r][R]-1<<"\n";
	solve(l,e[r][R]-2);
	solve(e[r][R],r);	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)s[i].clear(),e[i].clear();
		for(int i=1;i<=n;++i){
			int l,r;
			cin>>l>>r;
			s[l].push_back(r),e[r].push_back(l);
		}
		for(int i=1;i<=n;++i){
			sort(s[i].begin(),s[i].end());
			sort(e[i].begin(),e[i].end());
		}
		solve(1,n);
	}
	
	return 0;
}