#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[200005];
long long l[45],r[45];
char calc(long long x){
	if(x<=n)return a[x];
	long long tot=n;
	for(int i=1;i<=m;++i){
		if(tot+r[i]-l[i]+1>=x){
			return calc(l[i]+x-tot-1);
		}
		tot+=r[i]-l[i]+1;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int q;
		cin>>n>>m>>q>>(a+1);
		for(int i=1;i<=m;++i)cin>>l[i]>>r[i];
		for(int i=1;i<=q;++i){
			long long now;
			cin>>now;
			cout<<calc(now)<<"\n";
		}
	}
	
	return 0;
}