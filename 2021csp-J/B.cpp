#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int a[100005];
struct query{
	int type,x,v;
}q[200005];
vector<int>s[200005];
int sum[200005];
int lowbit(int x){
	return x&(-x);
}
void add(int x,int y){
	while(x<=200000){
		sum[x]+=y;
		x+=lowbit(x);
	}
}
int query(int x){
	int re=0;
	while(x){
		re+=sum[x];
		x-=lowbit(x);
	}
	return re;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],v.push_back(a[i]);
	for(int i=1;i<=m;++i){
		cin>>q[i].type;
		if(q[i].type==1)cin>>q[i].x>>q[i].v,v.push_back(q[i].v);
		else cin>>q[i].x;
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;++i){
		s[getid(a[i])].push_back(i);
		add(getid(a[i]),1);
	}
	for(int i=1;i<=m;++i){
		if(q[i].type==1){
			int id=getid(a[q[i].x]);
			for(auto now=s[id].begin();now!=s[id].end();++now){
				if(*now==q[i].x){
					s[id].erase(now);
					break;
				}
			}
			add(id,-1);
			id=getid(q[i].v);
			s[id].push_back(q[i].x);
			add(id,1);
			a[q[i].x]=q[i].v;
		}
		else{
			int ans=query(getid(a[q[i].x])-1);
			int id=getid(a[q[i].x]);
			sort(s[id].begin(),s[id].end());
			ans+=lower_bound(s[id].begin(),s[id].end(),q[i].x)-s[id].begin()+1;
			cout<<ans<<"\n";
		}
	}
	return 0;
}