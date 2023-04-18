#include<bits/stdc++.h>
using namespace std;
int a[200006],b[200005];
unordered_map<int,int>num,cnt;
int fa[200005],sz[200005];
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
	sz[y]+=sz[x];
}
int main(){
	b[0]=2147483647;
	int t;
	cin>>t;
	while(t--){
		num.clear();
		cnt.clear();
		int n,m;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],fa[i]=i;
		for(int i=1;i<=n;++i)cin>>b[i];
		cin>>m;
		for(int i=1;i<=m;++i){
			int now;
			cin>>now;
			++cnt[now];
		}
		bool ky=true;
		for(int i=1;i<=n;++i){
			if(a[i]<b[i]){
				ky=false;
				break;
			}
			if(a[i]==b[i])sz[i]=0;
			else sz[i]=1;
		}
		if(!ky){
			cout<<"NO\n";
			continue;
		}
		stack<int>s;
		s.push(0);
		for(int i=1;i<=n;++i){
			while(b[s.top()]<=b[i]){
				if(b[s.top()]==b[i]){
					int rtt=getfa(s.top());
					Merge(i,rtt);
				}
				s.pop();
			}
			s.push(i);
		}
		for(int i=1;i<=n;++i){
			if(getfa(i)==i){
				if(sz[i])++num[b[i]];
			}
		}
		for(const auto& p:num){
			if(p.second>cnt[p.first]){
				ky=false;
				break;
			}
		}
		if(ky)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}