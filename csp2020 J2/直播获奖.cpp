#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
vector<int>v;
int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int a[100005];
int sum[100005<<2];
void modify(int l,int r,int rt,int pos){
	if(l==r){
		++sum[rt];
		return;
	}
	int m=(r+l)>>1;
	if(pos<=m)modify(lson,pos);
	else modify(rson,pos);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int query(int l,int r,int rt,int k){
	if(l==r)return l;
	int m=(l+r)>>1;
	if(sum[rt<<1]>=k)return query(lson,k);
	else return query(rson,k-sum[rt<<1]);
}
int main(){
	int n,w;
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),v.push_back(a[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;++i){
		int now=i-max(1,i*w/100)+1;
		modify(1,n,1,getid(a[i]));
		printf("%d ",v[query(1,n,1,now)-1]);
	}
	return 0;
}
