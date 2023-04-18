#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+1+n);
		long long tot1=a[1],tot2=0;
		int l=1,r=n+1;
		while(l+1<r-1){
			++l,--r;
			tot1+=a[l],tot2+=a[r];
		}
		if(tot1>=tot2)cout<<"NO\n";
		else cout<<"YES\n";
	}	
	
	
	return 0;
}