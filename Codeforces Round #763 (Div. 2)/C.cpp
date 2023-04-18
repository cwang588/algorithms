#include<bits/stdc++.h>
using namespace std;
long long a[200005],tmp[200005];
int n;
bool check(long long m){
	for(int i=1;i<=n;++i)tmp[i]=a[i];
	for(int i=n;i>=3;--i){
		long long d=max(0ll,min(tmp[i]-m,a[i])/3);
		tmp[i]-=3*d;
		tmp[i-1]+=d;
		tmp[i-2]+=d*2;
	}
//	for(int i=3;i<=n;++i){
//		long long d=0;
//		if(tmp[i-2]<m)d=max((m-tmp[i-2]-1)/2+1,d);
//		if(tmp[i-1]<m)d=max(d,m-tmp[i-1]);
//		d=min(d,tmp[i]/3);
//		tmp[i]-=3*d;
//		tmp[i-2]+=2*d;
//		tmp[i-1]+=d;
//	}
	for(int i=1;i<=n;++i)if(tmp[i]<m)return false;
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		long long l=1,r=1000000001;
		while(l<r-1){
			int m=(l+r)>>1;
			if(check(m))l=m;
			else r=m;
		}
		cout<<l<<"\n";
	}
	return 0;
}