#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
int getid(long long x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
struct artist{
	long long l,r;
}a[200005];
vector<int>b[400005];
long long dp[400005],Max[400005];
int n;
int lowbit(int x){
	return x&(-x);
}
void modify(int x,long long k){
	while(x<=2*n){
		Max[x]=max(Max[x],k);
		x+=lowbit(x);
	}
}
long long query(int x){
	long long re=0;
	while(x){
		re=max(Max[x],re);
		x-=lowbit(x);
	}
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	long long k;
	cin>>k>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].l>>a[i].r;
		v.push_back(a[i].l);
		v.push_back(a[i].r);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;++i)b[getid(a[i].r)].push_back(i);
	int tot=v.size();
	long long ans=0;
	for(int i=1;i<=tot;++i){
		for(auto x:b[i]){
			dp[i]=max(dp[i],query(getid(a[x].l)-1)+a[x].r-a[x].l+1);
			modify(i,dp[i]);
		}
		ans=max(ans,dp[i]);
	}
	cout<<k-ans<<endl;
	return 0;
}
