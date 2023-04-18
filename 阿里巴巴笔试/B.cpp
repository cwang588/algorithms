#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
long long Min[2][1000006<<2],a[1000006],sum[2][1000006],ans[2][1000006];
void build(int l,int r,int rt){
	if(l==r){
		Min[0][rt]=sum[0][l];
		Min[1][rt]=sum[1][l];
		return;
	}
	int m=(l+r)>>1;
	build(lson); 
	build(rson);
	Min[0][rt]=min(Min[0][rt<<1],Min[0][rt<<1|1]); 
	Min[1][rt]=min(Min[1][rt<<1],Min[1][rt<<1|1]); 
}
long long query1(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return Min[0][rt];
	int m=(l+r)>>1;
	long long re=21474836471145146;
	if(nowl<=m)re=min(re,query1(lson,nowl,nowr));
	if(nowr>m)re=min(re,query1(rson,nowl,nowr));
	return re;
}
long long query2(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return Min[1][rt];
	int m=(l+r)>>1;
	long long re=21474836471145146;
	if(nowl<=m)re=min(re,query2(lson,nowl,nowr));
	if(nowr>m)re=min(re,query2(rson,nowl,nowr));
	return re;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)sum[0][i]=sum[0][i-1]+a[i];
	for(int i=n;i>=1;--i)sum[1][i]=sum[1][i+1]+a[i];
	build(1,n,1);
	for(int i=1;i<=n;++i){
		int l=max(1,i-m),r=i;
		ans[0][i]=max(ans[0][i],sum[0][i]-query1(1,n,1,l,r));
		if(i<=m)ans[0][i]=max(ans[0][i],sum[0][i]);
		ans[0][i]=max(ans[0][i],ans[0][i-1]);
	}
	for(int i=n;i>=1;--i){
		int l=i,r=min(i+m,n);
		ans[1][i]=max(ans[1][i],sum[1][i]-query2(1,n,1,l,r));
		if(i>=n-m+1)ans[1][i]=max(ans[1][i],sum[1][i]);
		ans[1][i]=max(ans[1][i],ans[1][i+1]);
	}
	long long tot=0;
	for(int i=0;i<=n;++i){
		tot=max(tot,ans[0][i]+ans[1][i+1]);
	}
	printf("%lld\n",tot);
	return 0;
}
