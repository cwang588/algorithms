#include<bits/stdc++.h>
using namespace std;
long long a[3005],sum[3005];
int num[3005];
int main(){
	int n;
	long long k;
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
		num[i]=num[i-1];
		if(!a[i])++num[i];
	}
	long long delta=-sum[n],ans=1;
	int m=num[n];
	if(abs(delta)>m*k)return !printf("-1\n");

	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			if(i<j){
				int t=num[j]-num[i];
				ans=max(ans,sum[j]-sum[i]+1+min(delta+(m-t)*k,t*k));
			}
			else{
				int t=num[i]-num[j];
				ans=max(ans,sum[j]-sum[i]+1-max(delta-(m-t)*k,-t*k));
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}