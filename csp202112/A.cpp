#include<bits/stdc++.h>
using namespace std;
int a[1000007];
int main(){
	int n,N;
	cin>>n>>N;
	for(int i=1;i<=n;++i)cin>>a[i];
	a[n+1]=N;
	long long ans=0;
	for(int i=1;i<=n+1;++i)ans+=1ll*(i-1)*(a[i]-a[i-1]);
	cout<<ans<<"\n";	
	return 0;
}