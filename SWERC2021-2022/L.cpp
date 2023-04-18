#include<bits/stdc++.h>
using namespace std;
int t[200005],a[200005];
vector<pair<long long,long long> >p;
int n;
int Max[200005];
int lowbit(int x){
	return x&(-x);
}
void modify(int x,int k){
	while(x<=n){
		Max[x]=max(Max[x],k);
		x+=lowbit(x);
	}
}
int query(int x){
	int re=0;
	while(x){
		re=max(re,Max[x]);
		x-=lowbit(x);
	}
	return re;
}
vector<long long>v;
int getid(long long x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int main(){
	long long V;
	cin>>n>>V;
	for(int i=1;i<=n;++i)cin>>t[i];
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		if(abs(a[i])>t[i]*V)continue;
		v.push_back(a[i]+V*t[i]);
		p.push_back(make_pair(V*t[i]-a[i],a[i]+V*t[i]));
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	sort(p.begin(),p.end());
	n=p.size();
	int ans=0;
	for(int i=0;i<n;++i){
		int now=query(getid(p[i].second))+1;
		ans=max(ans,now);
		modify(getid(p[i].second),now);
	}
	cout<<ans<<"\n";
	return 0;
}