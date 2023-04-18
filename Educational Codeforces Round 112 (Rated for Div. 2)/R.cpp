#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
struct work{
	int l,r,value;
}w[300005];
bool cmp(work a,work b){
	return a.value<b.value;
}
int Min[2000005<<2],col[2000005<<2];
void push_col(int rt){
	Min[rt<<1]+=col[rt];
	Min[rt<<1|1]+=col[rt];
	col[rt<<1]+=col[rt];
	col[rt<<1|1]+=col[rt];
	col[rt]=0;
}
void modify(int l,int r,int rt,int nowl,int nowr,int k){
	if(nowl<=l&&r<=nowr){
		Min[rt]+=k;
		col[rt]+=k;
		return;
	}
	push_col(rt);
	int m=(l+r)>>1;
	if(m>=nowl)modify(lson,nowl,nowr,k);
	if(m<nowr)modify(rson,nowl,nowr,k);
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
int query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return Min[rt];
	int m=(l+r)>>1,re=2147483647;
	push_col(rt);
	if(m>=nowl)re=min(re,query(lson,nowl,nowr));
	if(m<nowr)re=min(re,query(rson,nowl,nowr));
	return re;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>w[i].l>>w[i].r>>w[i].value;
	sort(w+1,w+1+n,cmp);
	int ans=2147483647;
	int l=0,r=0;
	while(r<n){
		if(l)modify(1,m*2-2,1,2*w[l].l-1,2*w[l].r-2,-1);
		++l;
		while(r<n&&!Min[1]){
			++r;
			modify(1,m*2-2,1,2*w[r].l-1,2*w[r].r-2,1);
		}
		if(!Min[1])break;
		while(query(1,m*2-2,1,2*w[l].l-1,2*w[l].r-2)>1){
			modify(1,m*2-2,1,2*w[l].l-1,2*w[l].r-2,-1);
			++l;
		}
		ans=min(ans,w[r].value-w[l].value);
	}
	cout<<ans<<endl;
	return 0;
}
