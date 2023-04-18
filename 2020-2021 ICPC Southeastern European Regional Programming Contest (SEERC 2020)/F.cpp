#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1 
using namespace std;
const long long mod=1000000007;
int h[3005],Min[3005],pos[3005];
void build(int l,int r,int rt){
	if(l==r){
		Min[rt]=h[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
int query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return Min[rt];
	int m=(l+r)>>1,re=2147483647;
	if(nowl<=m)re=min(re,query(lson,nowl,nowr));
	if(nowr>m)re=min(re,query(rson,nowl,nowr));
	return re;
}
long long dp[3005][3005<<2];
void modify(int l,int r,int rt,int pos,long long k,int id){
	if(l==r){
		dp[id][rt]=(dp[id][rt]+k)%mod;
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)modify(lson,pos,k,id);
	else modify(rson,pos,k,id);
	dp[id][rt]=(dp[id][rt<<1]+dp[id][rt<<1|1])%mod;
}
long long query(int l,int r,int rt,int nowl,int nowr,int id){
	if(nowl<=l&&r<=nowr)return dp[id][rt];
	int m=(l+r)>>1;
	long long re=0;
	if(nowl<=m)re+=query(lson,nowl,nowr,id);
	if(nowr>m)re+=query(rson,nowl,nowr,id);
	return re%mod;
}
long long ans[3005][3005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>h[i],pos[h[i]]=i;
	build(1,n,1);
	for(int i=1;i<=n;++i)ans[i][i]=1,modify(1,n,1,i,1,i);
	for(int len=2;len<=n;++len){
		for(int i=1;i+len-1<=n;++i){
			int l=i,r=i+len-1,minpos=pos[query(1,n,1,l,r)];
			long long tot1=0,tot2=0;
			if(l==minpos)tot1=1;
			else tot1=query(1,n,1,l,minpos-1,l)+1;
			if(r==minpos)tot2=1;
			else tot2=query(1,n,1,minpos+1,r,r)+1;
			ans[l][r]=tot1*tot2%mod;
			modify(1,n,1,r,ans[l][r],l);
			modify(1,n,1,l,ans[l][r],r);
		}
	}
	cout<<ans[1][n]<<endl;
	return 0;
}
