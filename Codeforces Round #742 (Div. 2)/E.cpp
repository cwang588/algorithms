#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
long long sum[200005<<2],lsum[200005<<2],rsum[200005<<2];
bool iscomplete[200005<<2];
int a[200005];
void update(int l,int r,int rt){
	int m=(l+r)>>1;
	if(a[m]>a[m+1]){
		iscomplete[rt]=false;
		lsum[rt]=lsum[rt<<1];
		rsum[rt]=rsum[rt<<1|1];
		sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	}
	else{
		if(iscomplete[rt<<1]&&iscomplete[rt<<1|1]){
			iscomplete[rt]=true;
			lsum[rt]=rsum[rt]=r-l+1;
			sum[rt]=sum[rt<<1]+sum[rt<<1|1]+1ll*(m-l+1)*(r-m);
		}
		else if(iscomplete[rt<<1]){
			iscomplete[rt]=false;
			lsum[rt]=m-l+1+lsum[rt<<1|1];
			rsum[rt]=rsum[rt<<1|1];
			sum[rt]=sum[rt<<1]+sum[rt<<1|1]+1ll*(m-l+1)*lsum[rt<<1|1];
		}
		else if(iscomplete[rt<<1|1]){
			iscomplete[rt]=false;
			lsum[rt]=lsum[rt<<1];
			rsum[rt]=rsum[rt<<1]+r-m;
			sum[rt]=sum[rt<<1]+sum[rt<<1|1]+1ll*(r-m)*rsum[rt<<1];
		}
		else{
			iscomplete[rt]=false;
			lsum[rt]=lsum[rt<<1];
			rsum[rt]=rsum[rt<<1|1];
			sum[rt]=sum[rt<<1]+sum[rt<<1|1]+rsum[rt<<1]*lsum[rt<<1|1];
		}
	}
}
void build(int l,int r,int rt){
	if(l==r){
		sum[rt]=lsum[rt]=rsum[rt]=iscomplete[rt]=1;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(l,r,rt);
}
void modify(int l,int r,int rt,int pos,int x){
	if(l==r){
		a[pos]=x;
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)modify(lson,pos,x);
	else modify(rson,pos,x);
	update(l,r,rt);
}
long long querylsum(int l,int r,int rt,int rmax){
	if(l==r)return 1;
	int m=(l+r)>>1;
	if(iscomplete[rt<<1]&&a[m]<=a[m+1])return min((long long)rmax-l+1,m-l+1+lsum[rt<<1|1]);
	else return min((long long)rmax-l+1,lsum[rt<<1]);
}
long long queryrsum(int l,int r,int rt,int lmax){
	if(l==r)return 1;
	int m=(l+r)>>1;
	if(iscomplete[rt<<1|1]&&a[m]<=a[m+1])return min((long long)r-lmax+1,r-m+rsum[rt<<1]);
	else return min((long long)r-lmax+1,rsum[rt<<1|1]);
}
long long query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return sum[rt];
	int m=(l+r)>>1;
	if(m>=nowr)return query(lson,nowl,nowr);
	if(m<nowl)return query(rson,nowl,nowr);
	long long ans=query(lson,nowl,nowr)+query(rson,nowl,nowr);
	if(a[m]<=a[m+1])ans+=queryrsum(l,m,rt<<1,nowl)*querylsum(m+1,r,rt<<1|1,nowr);
	return ans;
}
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>a[i];
	build(1,n,1);
	while(q--){
		int t;
		cin>>t;
		if(t==1){
			int p,to;
			cin>>p>>to;
			modify(1,n,1,p,to);
		}
		else{
			int ql,qr;
			cin>>ql>>qr;
			cout<<query(1,n,1,ql,qr)<<"\n";
		}
	}
	return 0;
}
