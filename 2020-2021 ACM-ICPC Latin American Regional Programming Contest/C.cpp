#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],sum[200005],f[200005][25],summ[200005];
int work(int a[],int n){
	int Min=2147483647,tot=0; 
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
		tot+=sum[i];
		Min=min(Min,sum[i]);
	}
	return tot-n*Min;
}
signed main(){
	int n;
	cin>>n;
	int tot=0;
	for(int i=1;i<=n;++i)cin>>a[i],tot+=a[i];
	tot/=n;
	for(int i=1;i<=2*n;++i)a[i]-=tot;
	int ans=work(a,n);
	for(int i=1;2*i<=n;++i)swap(a[i],a[n-i+1]);
	ans=min(ans,work(a,n));
	cout<<ans<<endl;
	return 0;
}
