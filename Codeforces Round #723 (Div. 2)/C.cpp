#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
long long a[200005],sum[200005],Min[200005<<2],col[200005<<2];
struct potion{
	long long value;
	int pos;
}p[200005];
int cnt;
bool cmp(potion x,potion y){
	if(x.value!=y.value)return x.value>y.value;
	return x.pos>y.pos;
}
void update(int l,int r,int rt){
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
void push_col(int l,int r,int rt){
	Min[rt<<1]+=col[rt]; 
	Min[rt<<1|1]+=col[rt]; 
	col[rt<<1]+=col[rt]; 
	col[rt<<1|1]+=col[rt]; 
	col[rt]=0;
}
void build(int l,int r,int rt){
	if(l==r){
		Min[rt]=sum[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(l,r,rt); 
}
void modify(int l,int r,int rt,int nowl,int nowr,long long x){
	if(nowl<=l&&r<=nowr){
		Min[rt]+=x;
		col[rt]+=x;
		return;
	}
	int m=(l+r)>>1;
	push_col(l,r,rt);
	if(nowl<=m)modify(lson,nowl,nowr,x);
	if(nowr>m)modify(rson,nowl,nowr,x);
	update(l,r,rt);
}
long long query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return Min[rt];
	int m=(l+r)>>1;
	push_col(l,r,rt);
	long long re=214748364711451466;
	if(nowl<=m)re=min(re,query(lson,nowl,nowr));
	if(nowr>m)re=min(re,query(rson,nowl,nowr));
	return re;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
	int ans=0;
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1];
		if(a[i]>=0)sum[i]+=a[i],++ans;
		else p[++cnt]={a[i],i};
	}
	build(1,n,1);
	sort(p+1,p+1+cnt,cmp);
	for(int i=1;i<=cnt;++i){
		long long tmp=query(1,n,1,p[i].pos,n);
		if(tmp+p[i].value>=0){
			++ans;
			modify(1,n,1,p[i].pos,n,p[i].value);
		}
	}
	printf("%d\n",ans);
	return 0;
}
