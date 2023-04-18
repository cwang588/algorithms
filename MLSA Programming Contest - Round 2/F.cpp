#include<bits/stdc++.h>
using namespace std;
struct clothes{
	long long a,b;
}c[100005];
bool cmp(clothes x,clothes y){
	if(x.a!=y.a)return x.a<y.a;
	return x.b>y.b;
}
int sum[100005],n;
int lowbit(int x){
	return x&(-x);
}
vector<long long>v;
int getid(long long x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void add(int x,int k){
	while(x<=n){
		sum[x]=max(sum[x],k);
		x+=lowbit(x);
	}
}
int query(int x){
	int re=0;
	while(x){
		re=max(re,sum[x]);
		x-=lowbit(x);
	}
	return re;
}
unordered_map<long long,bool>usd;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>c[i].a>>c[i].b,v.push_back(-c[i].b);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	sort(c+1,c+1+n,cmp);
	int ans=1;
	for(int i=1;i<=n;++i){
		if(usd[c[i].a])continue;
		usd[c[i].a]=true;
		int now=query(getid(-c[i].b)-1)+1;
		ans=max(now,ans);
		add(getid(-c[i].b),now);
	}
	cout<<ans;
	return 0;
}
