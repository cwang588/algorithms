#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
struct qj{
	long long X1,X2,Y1,Y2;
	int type;
}q[100005];
struct query{
	int l,r,id;
}a[200005];
int cnt,Min[3][200005<<2],col[3][200005<<2];
vector<int>in[100005],out[100005];
void push_col(int pos,int rt){
	Min[pos][rt<<1]+=col[pos][rt]; 
	Min[pos][rt<<1|1]+=col[pos][rt]; 
	col[pos][rt<<1]+=col[pos][rt]; 
	col[pos][rt<<1|1]+=col[pos][rt]; 
	col[pos][rt]=0;
}
void modify(int l,int r,int rt,int nowl,int nowr,int pos,int k){
	if(nowl<=l&&r<=nowr){
		Min[pos][rt]+=k;
		col[pos][rt]+=k;
		return;
	}
	push_col(pos,rt);
	int m=(l+r)>>1;
	if(nowl<=m)modify(lson,nowl,nowr,pos,k);
	if(nowr>m)modify(rson,nowl,nowr,pos,k);
	Min[pos][rt]=min(Min[pos][rt<<1],Min[pos][rt<<1|1]);
}
int query(int l,int r,int rt,int nowl,int nowr,int pos){
	if(nowl<=l&&r<=nowr)return Min[pos][rt];
	push_col(pos,rt);
	int m=(l+r)>>1,re=2147483647;
	if(nowl<=m)re=min(re,query(lson,nowl,nowr,pos));
	if(nowr>m)re=min(re,query(rson,nowl,nowr,pos));
	return re;
}
int find(int l,int r,int rt){
	if(l==r)return l;
	int m=(l+r)>>1;
	if(!Min[1][rt<<1])return find(lson);
	return find(rson);
}
int main(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>q[i].X1>>q[i].Y1>>q[i].X2>>q[i].Y2;
		long long aa=q[i].X2-q[i].X1,bb=q[i].Y2-q[i].Y1;
		if(aa>=d&&bb>=d)return !printf("NO\n");
		if(aa>=d)q[i].type=2;
		else if(bb>=d)q[i].type=1;
		else q[i].type=3;
	}
	for(int i=1;i<=n;++i){
		if(q[i].type==1){
			int l=(q[i].X1%d+d)%d+1,r=l+(q[i].X2-q[i].X1)-1;
			if(r<=d)modify(1,d,1,l,r,0,1);
			else{
				modify(1,d,1,l,d,0,1);
				modify(1,d,1,1,r-d,0,1);
			}
		}
		else if(q[i].type==2){
			int l=(q[i].Y1%d+d)%d+1,r=l+(q[i].Y2-q[i].Y1)-1;
			if(r<=d)modify(1,d,1,l,r,1,1);
			else{
				modify(1,d,1,l,d,1,1);
				modify(1,d,1,1,r-d,1,1);
			}
		}
		else{
			int l=(q[i].X1%d+d)%d+1,r=l+(q[i].X2-q[i].X1)-1;
			if(r<=d){
				modify(1,d,1,l,r,2,1);
				++cnt;
				a[cnt].l=l,a[cnt].r=r,a[cnt].id=i;
			}
			else{
				modify(1,d,1,l,d,2,1);
				++cnt;
				a[cnt].l=l,a[cnt].r=d,a[cnt].id=i;
				modify(1,d,1,1,r-d,2,1);
				++cnt;
				a[cnt].l=1,a[cnt].r=r-d,a[cnt].id=i;
			}
		}
	}
	for(int i=1;i<=cnt;++i){
		in[a[i].l].push_back(a[i].id);
		out[a[i].r+1].push_back(a[i].id);
	}
	for(int i=1;i<=d;++i){
		for(auto x:in[i]){
			int l=(q[x].Y1%d+d)%d+1,r=l+(q[x].Y2-q[x].Y1)-1;
			if(r<=d)modify(1,d,1,l,r,1,1);
			else{
				modify(1,d,1,l,d,1,1);
				modify(1,d,1,1,r-d,1,1);
			}
		}
		for(auto x:out[i]){
			int l=(q[x].Y1%d+d)%d+1,r=l+(q[x].Y2-q[x].Y1)-1;
			if(r<=d)modify(1,d,1,l,r,1,-1);
			else{
				modify(1,d,1,l,d,1,-1);
				modify(1,d,1,1,r-d,1,-1);
			}
		}
		if(query(1,d,1,i,i,0))continue;
		if(!Min[1][1])return !printf("YES\n%d %d\n",i-1,find(1,d,1)-1);
	}
	printf("NO\n");
	return 0;
}
