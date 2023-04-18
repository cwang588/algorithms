#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int L[2005],R[2005],sum[2005<<2],col[2005<<2];
void push_col(int l,int r,int rt){
	if(!col[rt])return;
	int m=(l+r)>>1;
	sum[rt<<1]+=col[rt]*(m-l+1);
	col[rt<<1]+=col[rt];
	sum[rt<<1|1]+=col[rt]*(r-m);
	col[rt<<1|1]+=col[rt];
	col[rt]=0;
}
void modify(int l,int r,int rt,int nowl,int nowr,long long k){
	if(nowl<=l&&r<=nowr){
		sum[rt]+=k*(r-l+1);
		col[rt]+=k;
		return;
	}
	int m=(l+r)>>1;
	push_col(l,r,rt);
	if(nowl<=m)modify(lson,nowl,nowr,k);
	if(nowr>m)modify(rson,nowl,nowr,k);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return sum[rt];
	int m=(l+r)>>1;
	push_col(l,r,rt);
	int re=0;
	if(nowl<=m)re+=query(lson,nowl,nowr);
	if(nowr>m)re+=query(rson,nowl,nowr);
	return re;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)scanf("%d%d",&L[i],&R[i]);
	int ans=0;
	for(int i=1;i+k-1<=n;++i){
		int tmp=0;
		for(int j=1;j<=m;++j){
			if(i>R[j]||i+k-1<L[j])continue;
			int RR=max(R[j],i+k-1),LL=min(L[j],i);
			tmp+=(R[j]-L[j]+1+k)-(RR-LL+1);
			modify(1,n,1,L[j],R[j],-1);
		}
		for(int j=1)
	}
	return 0;
} 
