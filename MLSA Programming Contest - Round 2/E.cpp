#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[500005],n;
long long sum[5][500005];
int lowbit(int x){
	return x&(-x);
}
long long query(int x,int id){
	long long re=0;
	while(x){
		re+=sum[id][x];
		re%=mod; 
		x-=lowbit(x);
	}
	return re;
}
void add(int x,long long k,int id){
	while(x<=n){
		sum[id][x]+=k;
		sum[id][x]%=mod;
		x+=lowbit(x);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		add(a[i],1,0);
		add(a[i],query(a[i]-1,0),1);
		add(a[i],query(n,1)-query(a[i],1),2);
		add(a[i],query(a[i]-1,2),3);
		add(a[i],query(n,3)-query(a[i],3),4);
	}
	cout<<(query(n,4)+mod)%mod;
	return 0;
}
