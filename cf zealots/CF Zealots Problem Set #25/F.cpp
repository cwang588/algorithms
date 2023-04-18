#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[2][300005];
int Head[2][300005],cnt[2];
void add(int x,int y,int id){
	++cnt[id];
	e[id][cnt[id]].from=x;
	e[id][cnt[id]].to=y;
	e[id][cnt[id]].nxt=Head[id][x];
	Head[id][x]=cnt[id];
}
int l[300005],r[300005],id;
void dfs1(int now){
	l[now]=++id;
	for(int i=Head[1][now];i;i=e[1][i].nxt){
		dfs1(e[1][i].to);
	}
	r[now]=++id;
}
int ans;
set<pair<int,int> >s;
int add(pair<int,int>now){
	s.insert(now);
	if(s.size()==1)return 1;
	auto it=s.find(now);
	if(it==s.begin()){
		++it;
		if(it->second<now.second)return 0;
		else return 1;
	}
	++it;
	if(it==s.end()){
		--it,--it;
		if(it->second<now.second)return 1;
		else return 0;
	}else{
		if(it->second<now.second)return 0;
		auto itt=it;
		--itt,--itt;
		if(itt->second<now.second)return 1;
		if(itt->second>it->second)return 1;
		return 0;
	}
}
void dfs2(int now,int cnt){
	auto tmp=make_pair(l[now],r[now]);
	cnt+=add(tmp);
	ans=max(ans,cnt);
	for(int i=Head[0][now];i;i=e[0][i].nxt)dfs2(e[0][i].to,cnt);
	s.erase(tmp);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ans=1;
		id=0;
		s.clear();
		int n;
		cin>>n;
		cnt[0]=cnt[1]=0;
		for(int i=1;i<=n;++i)Head[0][i]=Head[1][i]=0;
		for(int i=2;i<=n;++i){
			int x;
			cin>>x;
			add(x,i,0);
		}
		for(int i=2;i<=n;++i){
			int x;
			cin>>x;
			add(x,i,1);
		}
		dfs1(1);
		dfs2(1,0);
		cout<<ans<<"\n";
	}	
	
	return 0;
}