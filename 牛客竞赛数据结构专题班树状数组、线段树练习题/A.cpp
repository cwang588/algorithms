#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N=1000005;
long long Min[N<<2],col[N<<2],a[N];
void update(int rt){
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
void push_col(int rt){
	Min[rt<<1]+=col[rt];
	col[rt<<1]+=col[rt];
	Min[rt<<1|1]+=col[rt];
	col[rt<<1|1]+=col[rt];
	col[rt]=0;
}
void build(int l,int r,int rt){
	if(l==r){
		Min[rt]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(rt);
}
void modify(int l,int r,int rt,int nowl,int nowr,long long k){
	if(nowl<=l&&r<=nowr){
		col[rt]+=k;
		Min[rt]+=k;
		return;
	}
	push_col(rt);
	int m=(l+r)>>1;
	if(nowl<=m)modify(lson,nowl,nowr,k);
	if(nowr>m)modify(rson,nowl,nowr,k);
	update(rt);
	return;
}
long long query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return Min[rt];
	push_col(rt);
	long long re=1e16;
	int m=(l+r)>>1;
	if(nowl<=m)re=min(re,query(lson,nowl,nowr));
	if(nowr>m)re=min(re,query(rson,nowl,nowr));
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	build(1,n,1);
	for(int i=1;i<=m;++i){
		int l,r,val;
		cin>>val>>l>>r;
		if(query(1,n,1,l,r)<val){
			cout<<"-1\n"<<i<<"\n";
			return 0;
		}
		modify(1,n,1,l,r,-val);
	}
	cout<<"0\n";
	return 0;
}