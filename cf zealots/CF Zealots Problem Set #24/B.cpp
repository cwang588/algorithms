#include<bits/stdc++.h>
using namespace std;
long long calc(long long x){
	long long l=0,r=sqrt(x)+1,ans=0;
	while(l<r-1){
		long long m=(l+r)/2;
		if(m*m<=x)l=m;
		else r=m;		
	}
	ans+=l;
	l=0,r=sqrt(x)+1;
	while(l<r-1){
		long long m=(l+r)/2;
		if(m*(m+1)<=x)l=m;
		else r=m;		
	}
	ans+=l;
	l=0,r=sqrt(x)+1;
	while(l<r-1){
		long long m=(l+r)/2;
		if(m*(m+2)<=x)l=m;
		else r=m;		
	}
	ans+=l;
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long l,r;
		cin>>l>>r;
		cout<<calc(r)-calc(l-1)<<"\n";
	}
	return 0;
}