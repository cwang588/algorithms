#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long num[6][100005],sum[100005],origin[100005];
void add(int l,int r,long long x,int id){
	num[id][l]=(num[id][l]+x)%mod;
	num[id][r+1]=(num[id][r+1]-x)%mod;
} 
long long mi(long long x,long long y){
	long long re=1;
	for(int i=1;i<=y;++i)re=re*x%mod;
	return re;
}
void modify(int l,int r,long long x,int id){
	switch(id){
		case 0:
			add(l,r,x,0);
			break;
		case 1:
			add(l,r,x,1);
			add(l,r,x*(1-l)%mod,0);
			break;
		case 2:
			add(l,r,x*mi(l-1,2)%mod,0);
			add(l,r,-(l-1)*x*2%mod,1);
			add(l,r,x,2);
			break;
		case 3:
			add(l,r,-x*mi(l-1,3)%mod,0);
			add(l,r,x*mi(l-1,2)*3%mod,1);
			add(l,r,x*(1-l)*3%mod,2);
			add(l,r,x,3);
			break;
		case 4:
			add(l,r,x*mi(l-1,4)%mod,0);
			add(l,r,-x*mi(l-1,3)*4%mod,1);
			add(l,r,x*mi(l-1,2)*6%mod,2);
			add(l,r,-x*mi(l-1,1)*4%mod,3);
			add(l,r,x,4);
			break;
		default:
			add(l,r,-x*mi(l-1,5)%mod,0);
			add(l,r,x*mi(l-1,4)*5%mod,1);
			add(l,r,-x*mi(l-1,3)%mod*10,2);
			add(l,r,x*mi(l-1,2)%mod*10,3);
			add(l,r,-x*mi(l-1,1)*5%mod,4);
			add(l,r,x,5);
			break;
	}
}
int main(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i)cin>>origin[i];
	for(int i=1;i<=m;++i){
		int l,r,k;
		cin>>l>>r>>k;
		for(int j=0;j<=k;++j){
			long long x;
			cin>>x;
			modify(l,r,x,k-j);
		}
	}
	for(int i=1;i<=n;++i){
		sum[i]=origin[i];
		for(int j=0;j<=5;++j){
			num[j][i]=(num[j][i]+num[j][i-1])%mod;
			sum[i]=(sum[i]+num[j][i]*mi(i,j)%mod)%mod;
		}
		sum[i]=(sum[i]+sum[i-1])%mod;
		sum[i]=(sum[i]+mod)%mod;
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<((sum[r]-sum[l-1])%mod+mod)%mod<<endl;
	}
	return 0;
}
