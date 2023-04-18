#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=m;++i)cin>>b[i];
		long long ans=0;
		for(int i=1;i<=m;++i){
			int Min=2147483647,pos;
			for(int j=1;j<=n;++j){
				if(Min>a[j]){
					Min=a[j];
					pos=j;
				}
			}
			a[pos]=b[i];
		}
		for(int i=1;i<=n;++i)ans+=a[i];
		cout<<ans<<"\n";
	}
	
	
	return 0;
}