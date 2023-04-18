#include<bits/stdc++.h>
using namespace std;
int a[1005],n;
bool check(int k){
	int l=1,r=n;
	for(int i=1;i<=k;++i){
		while(r>=l&&a[r]>k-i+1)--r;
		if(r<l)return false;
		++l;
		--r;
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+1+n);
		int l=0,r=n+1;
		while(l<r-1){
			int m=(l+r)>>1;
			if(check(m))l=m;
			else r=m;
		}
		cout<<l<<"\n";
	}		
	return 0;
}