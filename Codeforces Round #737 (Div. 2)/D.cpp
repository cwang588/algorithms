#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
struct qj{
	int l,r;
};
vector<qj>q[300005];
int dp[300005];
vector<int>v;
int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int Min[300005<<2],col[300005<<2];
void build(int l,int r,int rt){
	if(l==r){
		Min[rt]=col[rt]=2147483647;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
void push_col(int l,int r,int rt){
	Min[rt<<1]=min(Min[rt<<1],col[rt]);
	Min[rt<<1|1]=min(Min[rt<<1|1],col[rt]);
	col[rt<<1]=min(col[rt<<1],col[rt]);
	col[rt<<1|1]=min(col[rt<<1|1],col[rt]);
	col[rt]=2147483647;
}
void modify(int l,int r,int rt,int nowl,int nowr,int k){
	if(nowl<=l&&r<=nowr){
		Min[rt]=min(Min[rt],k);
		col[rt]=min(col[rt],k);
		return;
	}
	int m=(l+r)>>1;
	push_col(l,r,rt);
	if(nowl<=m)modify(lson,nowl,nowr,k);
	if(nowr>m)modify(rson,nowl,nowr,k);
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
int query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return Min[rt];
	int m=(l+r)>>1;
	push_col(l,r,rt);
	int ans=2147483647;
	if(nowl<=m)ans=min(ans,query(lson,nowl,nowr));
	if(nowr>m)ans=min(ans,query(rson,nowl,nowr));
	return ans;
}
int last[300005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int id,l,r;
		cin>>id>>l>>r;
		q[id].push_back(qj{l,r});
		v.push_back(l);
		v.push_back(r);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int tot=v.size(),ans=n-1;
	for(int i=1;i<=n;++i){
		int tmpmin=21474847;
		for(auto x:q[i])tmpmin=min(tmpmin,query(1,tot,1,getid(x.l),getid(x.r)));
		dp[i]=min(i-1,tmpmin+i-1);
		for(auto x:q[i])modify(1,tot,1,getid(x.l),getid(x.r),dp[i]-i);
		ans=min(ans,dp[i]+n-i);
	}
	cout<<ans<<endl;
	return 0;
}
