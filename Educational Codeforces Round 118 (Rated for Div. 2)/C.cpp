#include<bits/stdc++.h>
using namespace std;
long long a[1005],h;
int n;
bool judge(long long k){
	long long tot=0;
	for(int i=2;i<=n;++i)tot+=min(a[i]-a[i-1],k);
	tot+=k;
	return tot>=h;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>h;
		for(int i=1;i<=n;++i)cin>>a[i];
		long long l=0,r=1000000000000000001;
		while(l<r-1){
			long long m=(l+r)/2;
			if(judge(m))r=m;
			else l=m;
		}
		cout<<r<<"\n";
	}	
	
	
	return 0;
}