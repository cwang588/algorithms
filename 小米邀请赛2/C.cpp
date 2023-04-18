#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005],c[200005];
long long sum[200005];
int lowbit(int x){
	return x&(-x);
}
int n,m;;
void add(int pos,long long x){
	while(pos<=n){
		sum[pos]+=x;
		pos+=lowbit(pos);
	}
}
long long tot(int pos){
	long long re=0;
	while(pos){
		re+=sum[pos];
		pos-=lowbit(pos);
	}
	return re;
}
long long summ[200005<<2],Min[200005<<2],cnt[200005<<2],se[200005<<2];
void build() 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>m){
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)cin>>b[i];
		for(int i=1;i<=n;++i)c[i]=max(c[i-1]+b[i],a[i]);
		
	}
	return 0;
}
