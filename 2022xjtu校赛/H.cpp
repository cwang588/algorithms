#include<bits/stdc++.h>
using namespace std;
struct wuzi{
	int l,r,id;
	bool operator <(const wuzi &a)const{
		if(l!=a.l)return l>a.l;
		if(r!=a.r)return r<a.r;
		return id>a.id;
	}
};
set<wuzi>s;
int ans[500005];
int main(){
	int n,m;
	cin>>n>>m;
	s.insert(wuzi{1,n,0});
	for(int i=1;i<=m;++i){
		int x;
		cin>>x;
		auto it=*(s.lower_bound(wuzi{x,x,i}));
		s.erase(it);
		if(it.l!=x)s.insert(wuzi{it.l,x-1,it.id});
		s.insert(wuzi{x,it.r,i});
	}
	for(auto x:s){
		for(int i=x.l;i<=x.r;++i)ans[i]=x.id;
	}
	for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
	return 0;
}