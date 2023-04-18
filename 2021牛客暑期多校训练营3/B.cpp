#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
bool usd[10005];
int v[5005][5005];
int Min[10005<<2],noww[10005];
void modify(int l,int r,int rt,int pos,int k,int op){
	if(l==r){
		if(op)Min[rt]=min(Min[rt],k);
		else Min[rt]=k;
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)modify(lson,pos,k,op);
	else modify(rson,pos,k,op);
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
int query(int l,int r,int rt){
	if(l==r)return l;
	int m=(l+r)>>1;
	if(Min[1]==Min[rt<<1])return query(lson);
	else return query(rson);
}
void build(int l,int r,int rt){
	if(l==r){
		Min[rt]=2147483647;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	Min[rt]=2147483647;
}
int main(){
	long long a,b,c,d,p;
	int n,m;
	cin>>n>>m>>a>>b>>c>>d>>p;
	long long now=a;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){ 
			now=(now*now*b+now*c+d)%p;
			v[i][j]=now;
		}
	}
	build(1,n+m,1);
//	modify(1,n+m,1,1,0);
	usd[1]=true;
	for(int i=1;i<=n+m;++i)noww[i]=2147483647,modify(1,n+m,1,i,2147483647,1);
	for(int i=n+1;i<=m+n;++i)noww[i]=v[1][i-n],modify(1,n+m,1,i,v[1][i-n],1);
	long long ans=0;
	int cnt=0;
	while(1){
		int value=Min[1],y=query(1,n+m,1);
		usd[y]=true;
		modify(1,n+m,1,y,2147483647,0);
		++cnt;
		ans+=value;
		if(y<=n){
			for(int i=n+1;i<=n+m;++i){
				if(usd[i])continue;
				if(noww[i]>v[y][i-n]){
					modify(1,n+m,1,i,v[y][i-n],1);
					noww[i]=v[y][i-n];
				}
			}
		}
		else{
			for(int i=1;i<=n;++i){
				if(usd[i])continue;
				if(noww[i]>v[i][y-n]){
					modify(1,n+m,1,i,v[i][y-n],1);
					noww[i]=v[i][y-n];
				}
			}
		}
		if(cnt==n+m-1)break;
	}
	cout<<ans<<endl;
	return 0;
}
