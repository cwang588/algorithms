#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
struct person{
	long long m,p;
}a[100005];
bool cmp(person x,person y){
	return x.m+x.p==y.m+y.p?(x.m<y.m):(x.m+x.p<y.m+y.p);
}
vector<long long>v;
int getid(long long x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
} 
long long sum[200005<<2][2];
int sz[200005<<2][2],tot,n;
void modify(int l,int r,int rt,int pos,int k,int op){
	if(k==1){
		++sz[rt][op];
		sum[rt][op]+=v[pos-1];
	}
	else{
		--sz[rt][op];
		sum[rt][op]-=v[pos-1];
	}
	if(l==r)return;
	int m=(l+r)>>1;
	if(pos<=m)modify(lson,pos,k,op);
	else modify(rson,pos,k,op); 
}
long long query(int l,int r,int rt,int k,int op){
	if(k==0)return 0;
	if(l==r)return sum[rt][op]/sz[rt][op]*k;
	int m=(l+r)>>1;
	if(sz[rt<<1][op]>=k)return query(lson,k,op);
	else return sum[rt<<1][op]+query(rson,k-sz[rt<<1][op],op);
}
bool check(int now,int i){
	return query(1,tot,1,now,0)<=query(1,tot,1,n-i,1)-query(1,tot,1,n-i-now,1);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i].m,v.push_back(a[i].m);
	for(int i=1;i<=n;++i)cin>>a[i].p,v.push_back(a[i].p);
	sort(a+1,a+1+n,cmp);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	tot=v.size();
	for(int i=1;i<=n;++i)modify(1,tot,1,getid(a[i].m),1,1);
	int ans=0;
	for(int i=1;i<n;++i){
		modify(1,tot,1,getid(a[i].p),1,0);
		modify(1,tot,1,getid(a[i].m),-1,1);
		int l=0,r=min(i,n-i)+1;
		while(l<r-1){
			int m=(l+r)>>1;
			if(check(m,i))l=m;
			else r=m;
		}
		ans=max(ans,l);
	}
	cout<<ans<<endl;
	return 0;
}
