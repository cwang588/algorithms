#include<bits/stdc++.h>
using namespace std;
int tmpans[]={0,1,4,5,8,11,13,14,16,23,25};
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		if(n<=10){
			cout<<tmpans[n]<<endl;
			continue;
		}
		long long tmp=1;
		while(tmp<n)tmp*=2;
		if(tmp==n){
			cout<<tmp*2<<endl;
			continue;
		}
		long long ans=tmp*2-(tmp-n+1);
		if(n==tmp/2+1)--ans;
		cout<<ans<<endl;
	}
	return 0;
}
