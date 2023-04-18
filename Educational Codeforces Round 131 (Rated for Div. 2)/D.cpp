#include<bits/stdc++.h>
using namespace std;
int a[500005];
struct qj{
	int l,r,id,ans;
	bool operator <(const qj& b)const{
		return r>b.r;
	}
}q[500005];
vector<qj>to[500005];
int ans[500005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)to[i].clear();
		for(int i=1;i<=n;++i){
			cin>>a[i];
			q[i].l=min(n,max(i/(a[i]+1)+1,1));
			if(!a[i])q[i].r=n;
			else q[i].r=min(n,max(i/a[i],1));
			q[i].id=i;
			to[q[i].l].push_back(q[i]);
		}
		priority_queue<qj>p;
		for(int i=1;i<=n;++i){
			for(auto x:to[i])p.push(x);
			qj now=p.top();
			p.pop();
			ans[now.id]=i;
		}
		for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
		for(int i=1;i<=n;++i)assert(i/ans[i]==a[i]);
		cout<<"\n";
	}
	
	
	return 0;
}