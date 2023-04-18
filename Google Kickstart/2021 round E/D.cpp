#include<bits/stdc++.h>
using namespace std;
double a[3005],sum[300005];
int main(){
	for(int i=1;i<=100;++i){
		a[i]=sum[i-1]/i+1;
		sum[i]=sum[i-1]+a[i];
		cout<<a[i]<<"\n";
	}
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		long long n;
		cin>>n;
		n=min(n,300000000ll);
		printf("Case #%d: %.7f\n",Case,a[n]);
	}
	
	return 0;
}