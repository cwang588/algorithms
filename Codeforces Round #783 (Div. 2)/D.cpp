#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int a[500005];
long long sum[5000005];
vector<long long>v;
int getid(long long x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
long long Max[500005<<2][3];
void push_up(int rt,int id){
	Max[rt][id]=max(Max[rt<<1][id],Max[rt<<1|1][id]);
}
void modify(int l,int r,int rt,int pos,long long value,int id){
	if(l==r){
		Max[rt][id]=max(Max[rt][id],value);
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)modify(lson,pos,value,id);
	else modify(rson,pos,value,id);
	push_up(rt,id);
}
long long query(int l,int r,int rt,int nowl,int nowr,int id){
	if(nowl>nowr)return -2147483647;
	if(nowl<=l&&r<=nowr)return Max[rt][id];
	int m=(l+r)>>1;
	long long re=-2147483647;
	if(nowl<=m)re=max(re,query(lson,nowl,nowr,id));
	if(nowr>m)re=max(re,query(rson,nowl,nowr,id));
	return re;
}
void build(int l,int r,int rt){
	if(l==r){
		for(int i=0;i<3;++i)Max[rt][i]=-2147483647;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	for(int i=0;i<3;++i)Max[rt][i]=-2147483647;
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		v.clear();
		v.push_back(0);
		for(int i=1;i<=n;++i)cin>>a[i],sum[i]=sum[i-1]+a[i],v.push_back(sum[i]);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		int nn=v.size();
		build(1,nn,1);
		for(int i=0;i<3;++i)modify(1,nn,1,getid(0),0,i);
		for(int i=1;i<=n;++i){
			int nowid=getid(sum[i]);
			long long ans1=query(1,nn,1,1,nowid-1,0)+i;
			long long ans2=query(1,nn,1,nowid,nowid,1);
			long long ans3=query(1,nn,1,nowid+1,nn,2)-i;
			long long ans=max(ans1,max(ans2,ans3));
			if(i==n)cout<<ans<<"\n";
			modify(1,nn,1,nowid,ans-i,0);
			modify(1,nn,1,nowid,ans,1);
			modify(1,nn,1,nowid,ans+i,2);
		}
	}
	
	return 0;
}