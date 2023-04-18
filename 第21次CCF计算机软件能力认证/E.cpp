#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const long long mod=2009731336725594113;
long long a[50][1000005];
int toid[55][55];
map<long long,int>id;
long long sb[5]={314882150829468584,427197303358170108,1022292690726729920,1698479428772363217,2006101093849356424};
set<long long>s;
long long tmp[35];
struct node{
	long long sum;
	int now,to[35];
	void work(int k){
		for(int i=1;i<=32;++i)tmp[i]=to[toid[i][k]];
		for(int i=1;i<=32;++i)to[i]=tmp[i];
		sum=to[1];
		now=toid[now][k];
	}
}T[1000005<<2];
long long mul(long long a,long long b){
	long long re=0,now=a;
	while(b){
		if(b&1)re=(re+now)%mod;
		now=(now+now)%mod;
		b>>=1;
	}
	return re;
}
void update(int rt){
	for(int i=1;i<=32;++i)T[rt].to[i]=T[rt<<1].to[i]+T[rt<<1|1].to[i];
	T[rt].sum=T[rt].to[1];
}
void push_col(int rt){
	T[rt<<1].work(T[rt].now);
	T[rt<<1|1].work(T[rt].now);
	T[rt].now=1;
}
void build(int l,int r,int rt){
	if(l==r){
		T[rt].now=1;
		for(int i=1;i<=32;++i)T[rt].to[i]=a[i][l];
		T[rt].sum=T[rt].to[1];
		return;
	}
	T[rt].now=1;
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	update(rt);
}
void modify(int l,int r,int rt,int nowl,int nowr,int id){
	if(nowl<=l&&r<=nowr){
		T[rt].work(id);
		return;
	}
	int m=(l+r)>>1;
	push_col(rt);
	if(nowl<=m)modify(lson,nowl,nowr,id);
	if(nowr>m)modify(rson,nowl,nowr,id);
	update(rt);
}
long long query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return T[rt].sum;
	int m=(l+r)>>1;
	push_col(rt);
	long long re=0;
	if(nowl<=m)re+=query(lson,nowl,nowr);
	if(nowr>m)re+=query(rson,nowl,nowr);
	return re;
}
void work(){
	for(int i=0;i<=4;++i)s.insert(sb[i]%mod);
	while(true){
		bool ky=false;
		for(auto x:s){
			for(auto y:s){
				if(s.count(mul(x,y)))continue;
				s.insert(mul(x,y));	
			}
		}
		if(!ky)break;
	}
	int idcnt=0;
	for(auto x:s){
		++idcnt;
		a[idcnt][1]=x;
		id[x]=idcnt;
	}
	for(int i=1;i<=32;++i){
		for(int j=1;j<=32;++j)toid[i][j]=id[mul(a[i][1],a[j][1])];
	}
	for(int i=1;i<=32;++i){
		long long now=a[i][1],tot=0;
		for(int j=1;j<=1000000;++j){
			tot=(tot+now)%mod;
			a[i][j]=tot%2019;
		}
	}	
}
int main(){
	work();
	int n,q;
	cin>>n>>q;
	build(1,n,1);
	while(q--){
		int l,r;
		cin>>l>>r;
		long long ans=query(1,n,1,l,r);
		cout<<ans<<endl;
		modify(1,n,1,l,r,id[sb[ans%5]]);
	}
	return 0;
} 
