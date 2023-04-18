#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int op[200005],a[200005],maxx[200005*4],minx[200005*4];
void build(int l,int r,int rt){
	if(l==r){
		maxx[rt]=a[l];
		minx[rt]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	maxx[rt]=max(maxx[rt<<1],maxx[rt<<1|1]);
	minx[rt]=min(minx[rt<<1],minx[rt<<1|1]);
}
int querymin(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return minx[rt];
	int m=(l+r)>>1;
	int re=2147483647;
	if(nowl<=m)re=min(re,querymin(lson,nowl,nowr));
	if(nowr>m)re=min(re,querymin(rson,nowl,nowr));
	return re;
}
int querymax(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return maxx[rt];
	int m=(l+r)>>1;
	int re=-2147483647;
	if(nowl<=m)re=max(re,querymax(lson,nowl,nowr));
	if(nowr>m)re=max(re,querymax(rson,nowl,nowr));
	return re;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			char tmp;
			cin>>tmp;
			if(tmp=='-')op[i]=-1;
			else op[i]=1;
		}
		for(int i=1;i<=n;++i)a[i]=a[i-1]+op[i];
		build(1,n,1);
		for(int i=1;i<=m;++i){
			int l,r;
			cin>>l>>r;
			int L1,R1,L2,R2;
			if(l>1)L1=min(0,querymin(1,n,1,1,l-1)),R1=max(0,querymax(1,n,1,1,l-1));
			else L1=R1=0;
			if(r<n)L2=querymin(1,n,1,r+1,n),R2=querymax(1,n,1,r+1,n);
			else L2=R2=a[n];
			int L,R;
			L=min(L1,L2+a[l-1]-a[r]);
			R=max(R1,R2+a[l-1]-a[r]);
			printf("%d\n",R-L+1);
		}
	}
	return 0;
}
