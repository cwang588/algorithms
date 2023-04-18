#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		long long ans=1,cnt1=1,cnt2=0,now=n;
		while(now>k){
			long long tmp1,tmp2;
			if(now%2){
				tmp1=cnt1,tmp2=cnt1+cnt2*2;
				ans+=cnt1*2;
				if(now>k+1)ans+=cnt2*2;
			}
			else{
				if(now>k+1){
					tmp1=cnt1*2+cnt2,tmp2=cnt2;
					ans+=tmp1+tmp2;
				}
				else ans+=cnt1*2;
			}
			cnt1=tmp1;
			cnt2=tmp2;
			now=(now+1)/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
