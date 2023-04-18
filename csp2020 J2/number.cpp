#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
long long a[1005][1005],dp[1005][1005],Max[1005<<2],col[1005<<2];
void build(int l,int r,int rt,int now){
	if(l==r){
		Max[rt]=dp[l][now-1]+a[l][now];
		return;
	}
	int m=(l+r)>>1;
	build(lson,now);
	build(rson,now);
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
} 
void push_col(int l,int r,int rt){
	Max[rt<<1]+=col[rt];
	Max[rt<<1|1]+=col[rt];
	col[rt<<1]+=col[rt];
	col[rt<<1|1]+=col[rt];
	col[rt]=0;
}
void modify(int l,int r,int rt,int nowl,int nowr,long long k){
	if(nowl<=l&&r<=nowr){
		Max[rt]+=k;
		col[rt]+=k;
		return;
	}
	int m=(l+r)>>1;
	push_col(l,r,rt);
	if(nowl<=m)modify(lson,nowl,nowr,k);
	if(nowr>m)modify(rson,nowl,nowr,k);
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]); 
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			long long t;
			scanf("%lld",&t);
			a[i][j]=a[i-1][j]+t;
		}
	}
	for(int i=1;i<=n;++i)dp[i][1]=a[i][1];
	for(int i=2;i<=m;++i){
		memset(Max,0,sizeof(Max));
		memset(col,0,sizeof(col));
		build(1,n,1,i);
		dp[1][i]=Max[1];
		for(int j=1;j<n;++j){
			modify(1,n,1,1,j,a[j+1][i]-a[j][i]);
			modify(1,n,1,j+1,n,-(a[j][i]-a[j-1][i]));
			dp[j+1][i]=Max[1];
		}
	}
	printf("%lld\n",dp[n][m]);
	return 0;
}
