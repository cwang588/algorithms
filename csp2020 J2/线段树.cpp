#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
long long a[100005],sum[100005<<2],col[100005<<2];
void build(int l,int r,int rt){
	if(l==r){
		sum[rt]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
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
long long query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return sum[rt];
	int m=(l+r)>>1;
	push_col(l,r,rt);
	long long re=0;
	if(nowl<=m)re+=query(lson,nowl,nowr);
	if(nowr>m)re+=query(rson,nowl,nowr);
	return re;
}
int main(){
	int n,m; 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	build(1,n,1);
	for(int i=1;i<=m;++i){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x,y;
			long long k;
			scanf("%d%d%lld",&x,&y,&k);
			modify(1,n,1,x,y,k);
		}
		else{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,n,1,x,y));
		}
	}
	return 0;
}
