#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int n,k;
bool check(long long x){
	long long tot=x+a[1];
	for(int i=2;i<=n;++i){
		if(a[i]*100>tot*k)return false;
		tot+=a[i];
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)cin>>a[i];
		long long l=0,r=1e15;
		while(l<r-1){
			long long m=(l+r)/2;
			if(check(m))r=m;
			else l=m;
		}
		if(check(l))cout<<l<<"\n";
		else cout<<r<<"\n";
	}
	
	
	return 0;
}