#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int a[500005];
long long sum[500005*4];
void update(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt){
	if(l==r){
		sum[rt]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(rt);
}
void modify(int l,int r,int rt,int pos,int x){
	if(l==r){
		sum[rt]+=x;
		return;
	}
	int m=(l+r)>>1;
	if(m>=pos)modify(lson,pos,x);
	else modify(rson,pos,x);
	update(rt);
}
long long query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return sum[rt];
	int m=(l+r)>>1;
	long long re=0;
	if(m>=nowl)re+=query(lson,nowl,nowr);
	if(m<nowr)re+=query(rson,nowl,nowr);
	return re;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	build(1,n,1);
	while(m--){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)modify(1,n,1,x,y);
		else printf("%lld\n",query(1,n,1,x,y));
	}
	return 0;	
}
