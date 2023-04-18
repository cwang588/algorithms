#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int a[500005];
long long sum[500005<<2];
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
void modify(int l,int r,int rt,int pos,long long k){
	if(l==r){
		sum[rt]+=k;
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)modify(lson,pos,k);
	else modify(rson,pos,k);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
long long query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return sum[rt];
	int m=(l+r)>>1;
	long long ans=0;
	if(nowl<=m)ans+=query(lson,nowl,nowr);
	if(nowr>m)ans+=query(rson,nowl,nowr);
	return ans;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	build(1,n,1);
	for(int i=1;i<=m;++i){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)modify(1,n,1,x,y);
		else printf("%lld\n",query(1,n,1,x,y));
	}
	return 0;
}
