#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
int main(){
	int n;
	cin>>n;
	long long Max=0;
	for(int i=1;i<=n;++i)cin>>a[i],Max=max(Max,a[i]);
	long long now=0;
	for(int i=1;i<=n;++i)now=gcd(now,Max-a[i]);
	long long tot=0;
	for(int i=1;i<=n;++i)tot+=(Max-a[i])/now;
	cout<<tot<<" "<<now<<"\n";	
	return 0;
}