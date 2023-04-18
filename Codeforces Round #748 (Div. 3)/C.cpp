#include<bits/stdc++.h>
using namespace std;
long long a[400005];
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		int k;
		cin>>n>>k;
		for(int i=1;i<=k;++i){
			long long tmp;
			cin>>tmp;
			a[i]=n-tmp;
		}
		sort(a+1,a+1+k);
		long long tot=0;
		bool ky=false;
		for(int i=1;i<=k;++i){
			tot+=a[i];
			if(tot>=n){
				ky=true;
				cout<<i-1<<"\n";
				break;
			}
		}
		if(!ky)cout<<k<<"\n";
	}
	
	return 0;
}