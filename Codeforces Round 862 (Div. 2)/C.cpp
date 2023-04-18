#include<bits/stdc++.h>
using namespace std;
long long k[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i)cin>>k[i];
		sort(k+1,k+1+n);
		for(int i=1;i<=m;++i){
			long long a,b,c;
			cin>>a>>b>>c;
			long long tmp=2*sqrt(a*c),l,r;
			if(tmp*tmp==a*c*4){
				l=-tmp+1+b,r=tmp-1+b;
			}else{
				l=-tmp+b,r=tmp+b;
			}
			int pos=lower_bound(k+1,k+n+1,l)-k;
			if(pos>n||k[pos]>r)cout<<"NO\n";
			else cout<<"YES\n"<<k[pos]<<"\n";
		}
	}
	
	return 0;
} 
