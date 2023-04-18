#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[16006],b[16006];
long long suma[16006],sumb[16006];
signed main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,m,k;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],suma[i]=suma[i-1]+a[i];
		cin>>m;
		for(int i=1;i<=m;++i)cin>>b[i],sumb[i]=sumb[i-1]+b[i];
		cin>>k;
		long long ans=0;
		for(int i=0;i<=k;++i){
			int num1=n-min(i,n),num2=m-min(k-i,m);
			long long now1=1e16,now2=1e16;
			for(int j=num1;j<=n;++j)now1=min(now1,suma[j]-suma[j-num1]);
			for(int j=num2;j<=m;++j)now2=min(now2,sumb[j]-sumb[j-num2]);
			ans=max(ans,suma[n]+sumb[m]-now1-now2);
		}
		printf("Case #%lld: %lld\n",Case,ans);
		for(int i=0;i<=n;++i)a[i]=suma[i]=0;
		for(int i=0;i<=m;++i)b[i]=sumb[i]=0;
	}
	return 0;
}