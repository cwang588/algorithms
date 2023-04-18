#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	a[n+1]=a[1]+m;
	int ans=0;
	for(int i=1;i<=n;++i)ans+=(a[i+1]-a[i]-2)/2;
	cout<<ans<<"\n";
	return 0;
}