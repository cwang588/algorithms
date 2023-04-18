#include<bits/stdc++.h>
using namespace std;
long long a[16006],b[16006];
long long suma[16006],sumb[16006];
int main(){
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
			long long now1=0,now2=0;
			int re=min(n,i);
			for(int j=0;j<=re;++j)now1=max(now1,suma[j]+suma[n]-suma[n-(re-j)]);
			re=min(m,k-i);
			for(int j=0;j<=re;++j)now2=max(now2,sumb[j]+sumb[m]-sumb[m-(re-j)]);
			ans=max(ans,now1+now2);
		}
		printf("Case #%d: %I64d\n",Case,ans);
		for(int i=0;i<=n;++i)a[i]=suma[i]=0;
		for(int i=0;i<=m;++i)b[i]=sumb[i]=0;
	}
	return 0;
}