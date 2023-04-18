#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		long long n;
		cin>>n;
		int ans=0;
		for(long long i=1;i*i<=n*2;++i){
			if(2*n%i)continue;
			if(2*n/i+1-i>0&&(2*n/i+1-i)%2==0)++ans;
			if(i*i<2*n){
				long long tmp=2*n/i;
				if(2*n/tmp+1-tmp>0&&(2*n/tmp+1-tmp)%2==0)++ans;
			}
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	return 0;
}