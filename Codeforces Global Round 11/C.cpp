#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int x[100005],y[100005],t[100005];
int dp[100005],Max[4000005];
void modify(int l,int r,int rt,int pos,int k){
	if(l==r){
		Max[rt]=max(Max[rt],k);
		return;
	}
	int m=(l+r)>>1;
	if(m>=pos)modify(lson,pos,k);
	else modify(rson,pos,k);
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
int query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return Max[rt];
	int m=(l+r)>>1,re=0;
	if(m>=nowl)re=max(re,query(lson,nowl,nowr));
	if(m<nowr)re=max(re,query(rson,nowl,nowr));
	return re;
}
int main(){
	int n,m;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i)scanf("%d%d%d",&t[i],&x[i],&y[i]);
	x[0]=y[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=i-1;j>=0&&t[i]-t[j]<=1000;--j){
			if((j==0||dp[j])&&abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		if(t[i]>1000){
			dp[i]=max(dp[i],1+query(1,1000000,1,1,t[i]-1000));
			dp[i]=max(dp[i],1);
		}
		modify(1,1000000,1,t[i],dp[i]);
	}
	int ans=0;
	for(int i=1;i<=n;++i)ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}
