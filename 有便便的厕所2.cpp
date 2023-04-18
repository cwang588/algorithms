#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N=1000000;
long long x[1000005<<2],d[1000005<<2],col1[1000005<<2],col2[1000005<<2];
void push_col(int rt){
	x[rt<<1]+=col1[rt];
	x[rt<<1|1]+=col1[rt];
	d[rt<<1]+=col2[rt];
	d[rt<<1|1]+=col2[rt];
	col1[rt]=col2[rt]=0;
}
void modify(int l,int r,int rt,int nowl,int nowr,int p,int q){
	if(nowl<=l&&r<=nowr){
		x[rt]+=p;
		d[rt]+=q;
		col1[rt]+=p;
		col2[rt]+=q;
		return;
	}
	push_col(rt);
	int m=(l+r)>>1;
	if(nowl<=m)modify(lson,nowl,nowr,p,q);
	if(nowr>m)modify(rson,nowl,nowr,p,q);
}
long long query1(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return x[rt]*(r-l+1)+d[rt]*(r-l)*(r-l+1)/2;
	push_col(rt);
	int m=(l+r)>>1;
	long long re=0;
	if(nowl<=m)re+=query1(lson,nowl,nowr);
	if(nowr>m)re+=query1(rson,nowl,nowr);
	return re;
}
long long query2(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return x[rt]*x[rt]*(r-l+1)+x[rt]*d[rt]*(r-l)*(r-l+1)+d[rt]*d[rt]*(r-l+1)*(r-l)*(2*(r-l+1)-1)/6;
	push_col(rt);
	int m=(l+r)>>1;
	long long re=0;
	if(nowl<=m)re+=query2(lson,nowl,nowr);
	if(nowr>m)re+=query2(rson,nowl,nowr);
	return re;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x;
			scanf("%d",&x);
			modify(1,N,1,x,x,x,1);
		}
		else if(t==2){
			int l,r;
			scanf("%d%d",&l,&r);
			modify(1,N,1,l,r,l,1);
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld %lld\n",query1(1,N,1,l,r),query2(1,N,1,l,r));	
		}
	}
	return 0;
}
