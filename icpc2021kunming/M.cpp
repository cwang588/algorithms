#include<bits/stdc++.h>
#define ls(x) T[x].l
#define rs(x) T[x].r
using namespace std;
struct node{
	int l,r;
	long long tot;
}T[1000005*33];
int cnt,root[1000005],num[1000005];
long long a[1000005];
vector<long long>v;
int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int getpos(int x){
	return upper_bound(v.begin(),v.end(),x)-v.begin();
}
int build(int l,int r){
	int node=++cnt;	
	if(l==r)T[node].tot=0;
	else{
		int m=(l+r)>>1;
		T[node].l=build(l,m);
		T[node].r=build(m+1,r);
		T[node].tot=T[ls(node)].tot+T[rs(node)].tot;
	}
	return node;
}
int modify(int l,int r,int rt,int pos){
	T[++cnt]=T[rt];
	int node=cnt;
	if(l==r){
		T[node].tot+=v[pos-1];
	}
	else{
		int m=(l+r)>>1;
		if(pos<=m)T[node].l=modify(l,m,T[rt].l,pos);
		else T[node].r=modify(m+1,r,T[rt].r,pos);
		T[node].tot=T[ls(node)].tot+T[rs(node)].tot;
	}
	return node;
} 
long long query(int l,int r,int node,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return T[node].tot;
	int m=(l+r)>>1;
	long long re=0;
	if(nowl<=m)re+=query(l,m,ls(node),nowl,nowr);
	if(nowr>m)re+=query(m+1,r,rs(node),nowl,nowr);
	return re;
}
int main(){
	int n,m;
//	printf("%d\n",sizeof(struct node));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		v.push_back(a[i]);
		num[i]=num[i-1]+(a[i]==1?1:0);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
//	root[0]=build(1,n);
	for(int i=1;i<=n;++i)root[i]=modify(1,n,root[i-1],getid(a[i]));
	long long last=0;
	while(m--){
		int l,r,L,R;
		scanf("%d%d",&l,&r);
		L=(l+last)%n+1,R=(r+last)%n+1;
		l=min(L,R),r=max(L,R);
		if(num[r]-num[l-1]==0){
			last=1;
			printf("1\n");
			continue;
		}
		long long now=1,ans;
		while(1){
			long long tot=query(1,n,root[r],1,getpos(now+1))-query(1,n,root[l-1],1,getpos(now+1));
			if(tot>now){
				now=tot+1;
				continue;
			}
		//	long long tmp=query(1,n,root[r],1,getpos(now+1))-query(1,n,root[l-1],1,getpos(now+1));
		//	if(tmp>tot)now=tmp;
			else{
				ans=tot+1;
				break;
			}
		}
		printf("%lld\n",ans);
		last=ans;
	}
	return 0;
}
