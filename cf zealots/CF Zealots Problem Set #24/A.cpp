#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int n,m;
bool check(int x){
	long long cnt=0;
	for(int i=1;i<=x;++i){
		cnt+=m/a[i];
	}
	return cnt<=n-x;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	int l=0,r=n+1;
	while(l<r-1){
		int m=(l+r)>>1;
		if(check(m))l=m;
		else r=m;
	}
	cout<<l<<"\n";
	return 0;
}