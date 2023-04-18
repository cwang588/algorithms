#include<bits/stdc++.h>
using namespace std;
long long a[100005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long sum=0;
		for(int i=1;i<=n;++i)cin>>a[i],sum+=a[i];
		sort(a+1,a+1+n,cmp);
		double ans=-2147483647.0;
		long long tot=0;
		for(int i=1;i<=n;++i){
			tot+=a[i];
			ans=max(ans,1.0*tot/i+1.0*(sum-tot)/(n-i));
		}
		printf("%.8lf\n",ans);
	}
	return 0;
}
