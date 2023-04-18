#include<bits/stdc++.h>
using namespace std;
long long a[1045][1959];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int m,n,q;
		cin>>n>>m>>q;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)cin>>a[i][j];
		}
		long long ans=0;
		for(int i=1;i<=m;++i){
			long long Max=0;
			for(int j=1;j<=n;++j)Max=max(Max,a[j][i]);
			ans+=Max-a[q][i];
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	
	return 0;
}