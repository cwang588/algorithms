#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
using namespace std;
typedef long long ll;
bool usd[605][605];
long long x[605],y[605];
double getdis(int i,int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
double dp1[605][605],dp2[605][605];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(usd,0,sizeof(usd));
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>x[i]>>y[i],x[i+n]=x[i],y[i+n]=y[i];
		int m;
		cin>>m;
		for(int i=1;i<=m;++i){
			int t1,t2;
			cin>>t1>>t2;
			usd[t1][t2]=usd[t1][t2+n]=usd[t1+n][t2]=usd[t1+n][t2+n]=true;
			usd[t2][t1]=usd[t2][t1+n]=usd[t2+n][t1]=usd[t2+n][t1+n]=true;
		}
		double ans=0.0;
		for(int len=1;len<=n;++len){
			for(int l=1;l+len-1<=n*2;++l){
				int r=l+len-1;
				for(int k=max(1,r-n+1);k<l;++k){
					if(usd[k][l])dp1[k][r]=max(dp1[k][r],dp1[l][r]+getdis(k,l));
					if(usd[k][r])dp1[k][r]=max(dp1[k][r],dp2[l][r]+getdis(k,r));
				}
				for(int k=r+1;k<=min(l+n-1,n*2);++k){
					if(usd[l][k])dp2[l][k]=max(dp2[l][k],dp1[l][r]+getdis(k,l));
					if(usd[r][k])dp2[l][k]=max(dp2[l][k],dp2[l][r]+getdis(k,r));
				}
				ans=max(ans,dp1[l][r]);
				ans=max(ans,dp2[l][r]);
			}
			
		}
		printf("%.8f\n",ans);
	}
	
	
	
	return 0;
}