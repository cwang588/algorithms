#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
unordered_map<int,int>a[200005];
set<pair<int,int>>s[200005];
bool isNotPrime[200505];
int prime[200005],cnt;
void init(){
	isNotPrime[1]=false;
	isNotPrime[2]=true;
	prime[++cnt]=2;
	for(int i=2;i<=500;++i){
		if(!isNotPrime[i]){
			prime[++cnt]=i;
		}
		for(int j=1;j<=cnt&&prime[j]*i<=500;++j){
			isNotPrime[prime[j]*i]=true;
			if(i%prime[j]==0)break;
		}
	}
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int qpow(int a,int b,int p){
	int re=1,now=a;
	while(b){
		if(b&1)re=1ll*re*now%p;
		now=1ll*now*now%p;
		b>>=1;
	}
	return re;
}
int main(){
	init();
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;++i){
		int t;
		cin>>t;
		ans=gcd(ans,t);
		for(int j=1;j<=cnt&&prime[j]<=t;++j){
			int cnt=0,now=prime[j];
			while(t%now==0){
				++cnt;
				t/=now;
			}
			if(!cnt)continue;
			a[i][now]=cnt;
			s[now].insert(make_pair(cnt,i));
		}
		if(t>1){
			a[i][t]=1;
			s[t].insert(make_pair(1,i));
		}
		
	}
	for(int i=1;i<=m;++i){
		int pos,t;
		cin>>pos>>t;
		for(int j=1;j<=cnt&&prime[j]<=t;++j){
			int cnt=0,now=prime[j];
			while(t%now==0){
				++cnt;
				t/=now;
			}
			if(!cnt)continue;
			int num1=0;
			if(s[now].size()==n)num1=s[now].begin()->first;
			if(a[pos].count(now))s[now].erase(make_pair(a[pos][now],pos));
			a[pos][now]+=cnt;
			s[now].insert(make_pair(a[pos][now],pos));
			int num2=0;
			if(s[now].size()==n)num2=s[now].begin()->first;
			ans=1ll*ans*qpow(now,num2-num1,mod)%mod;
		}
		if(t>1){
			int num1=0;
			if(s[t].size()==n)num1=s[t].begin()->first;
			if(a[pos].count(t))s[t].erase(make_pair(a[pos][t],pos));
			++a[pos][t];
			s[t].insert(make_pair(a[pos][t],pos));
			int num2=0;
			if(s[t].size()==n)num2=s[t].begin()->first;
			ans=1ll*ans*qpow(t,num2-num1,mod)%mod;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}