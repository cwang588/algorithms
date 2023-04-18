#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const long long mod=1000000007;
struct matrix{
	long long a[3][3];
	void init(bool isZero){
		memset(a,0,sizeof(a));
		if(!isZero){
			for(int i=1;i<=2;++i)a[i][i]=1;
		}
	}
	matrix operator *(const matrix &b){
		matrix ans;
		ans.init(true);
		for(int i=1;i<=2;++i){
			for(int j=1;j<=2;++j){
				for(int k=1;k<=2;++k)ans.a[i][j]=(ans.a[i][j]+a[i][k]*b.a[k][j])%mod;
			}
		}
		return ans;
	}
};
//matrix mi[2][100005];
//void init(){
//	mi[0][0].init(false);
//	mi[1][0].init(false);
//	matrix m0,m1;
//	m0.init(false),m1.init(false);
//	m0.a[2][1]=m1.a[1][2]=1;
//	for(int i=1;i<=100000;++i)mi[0][i]=mi[0][i-1]*m0;
//	for(int i=1;i<=100000;++i)mi[1][i]=mi[1][i-1]*m1;
//}
int type[100005];
matrix mul[100005<<2];
void build(int l,int r,int rt){
	if(l==r){
		mul[rt].init(false);
		if(!type[l])mul[rt].a[2][1]=1;
		else mul[rt].a[1][2]=1;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	mul[rt]=mul[rt<<1|1]*mul[rt<<1];
}
matrix query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return mul[rt];
	int m=(l+r)>>1;
	matrix re;
	re.init(false);
	if(nowl<=m)re=re*query(lson,nowl,nowr);
	if(nowr>m)re=query(rson,nowl,nowr)*re;
	return re;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;++i){
		char t;
		cin>>t;
		if(t=='/')type[i]=0;
		else type[i]=1;
	}
	build(1,n,1);
	while(m--){
		int l,r,x,y;
		cin>>l>>r>>x>>y;
		matrix ans=query(1,n,1,l,r-1);
		++x,++y;
		cout<<ans.a[y][x]<<"\n";
	}
	return 0;
}