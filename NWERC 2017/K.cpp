#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int a[5005];
struct node{
	vector<int>num;
	vector<double>dp;
}T[5005<<2],tmpp[5005];
void build(int l,int r,int rt){
	if(l==r){
		T[rt]=tmpp[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	int len1=T[rt<<1].num.size(),len2=T[rt<<1|1].num.size();
	for(int i=0;i<len1;++i){
		int x=T[rt<<1].num[i];
		T[rt].num.push_back(x);
		double tmp=0.0;
		for(int j=0;j<len2;++j){
			int y=T[rt<<1|1].num[j];
			tmp+=1.0*a[x]/(a[x]+a[y])*T[rt<<1|1].dp[j];
		}
		tmp*=T[rt<<1].dp[i];
		T[rt].dp.push_back(tmp);
	}
	for(int i=0;i<len2;++i){
		int x=T[rt<<1|1].num[i];
		T[rt].num.push_back(x);
		double tmp=0.0;
		for(int j=0;j<len1;++j){
			int y=T[rt<<1].num[j];
			tmp+=1.0*a[x]/(a[x]+a[y])*T[rt<<1].dp[j];
		}
		T[rt].dp.push_back(tmp*T[rt<<1|1].dp[i]);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+2,a+1+n);
	int nn=1;
	while(nn<=n)nn<<=1;
	nn>>=1;
	for(int i=1;i<=n-(n-nn)*2;++i){
		tmpp[i].num.push_back(i);
		tmpp[i].dp.push_back(1);
	}
	int cnt=n-(n-nn)*2;
	for(int i=n-(n-nn)*2+1;i<=n;i+=2){
		++cnt;
		tmpp[cnt].num.push_back(i);
		tmpp[cnt].dp.push_back(1.0*a[i]/(a[i]+a[i+1]));
		tmpp[cnt].num.push_back(i+1);
		tmpp[cnt].dp.push_back(1.0*a[i+1]/(a[i]+a[i+1]));
	}
	build(1,nn,1);
	int len=T[1].num.size();
	for(int i=0;i<len;++i){
		if(T[1].num[i]!=1)continue;
		printf("%.8lf\n",T[1].dp[i]);
		break;
	}
	return 0;
}
