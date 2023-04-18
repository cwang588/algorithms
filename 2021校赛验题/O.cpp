#include<bits/stdc++.h>
using namespace std;
struct segment{
	long long l,r;
}s[200005];
bool cmp(segment x,segment y){
	if(x.l!=y.l)return x.l<y.l;
	return x.r>y.r;
}
vector<long long>v;
int getid(long long x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int a[400005];
unordered_map<long long,int>m;
int main(){
	ios::sync_with_stdio(0);
	int n;
	long long L;
	cin>>n>>L;
	for(int i=1;i<=n;++i)cin>>s[i].l>>s[i].r,v.push_back(s[i].l),v.push_back(s[i].r+1);
	sort(s+1,s+1+n,cmp);
	long long now=1,nowr=0;
	int ans1=0;
	while(nowr<L&&now<=n){
		long long tmp=0;
		while(s[now].l<=nowr&&now<=n){
			tmp=max(tmp,s[now].r);
			++now;
		}
		nowr=tmp;
		++ans1;
	}
	printf("%d ",ans1);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<v.size();++i)m[v[i]]=i+1;
	for(int i=1;i<=n;++i){
		++a[m[s[i].l]];
		--a[m[s[i].r+1]];
	}
	int ans2=2147483647;
	for(int i=1;i<v.size();++i){
		a[i]+=a[i-1];
		ans2=min(ans2,a[i]);
	}
	printf("%d\n",n-ans2+1);
	return 0;
}
