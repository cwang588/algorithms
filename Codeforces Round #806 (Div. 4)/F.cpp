#include<bits/stdc++.h>
using namespace std;
int a[200005],sum[200005],n;
int lowbit(int x){
	return x&(-x);
}
void add(int x){
	while(x<=n){
		++sum[x];
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
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n+1;++i)sum[i]=0;
		for(int i=1;i<=n;++i)cin>>a[i];
		long long ans=0;
		for(int i=1;i<=n;++i){
			if(a[i]>=i)continue;
			ans+=query(a[i]);
			add(i+1);
		}
		cout<<ans<<"\n";
	}
	
	
	
	return 0;
}