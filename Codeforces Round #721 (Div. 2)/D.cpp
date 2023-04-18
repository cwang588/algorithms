#include<bits/stdc++.h>
using namespace std;
unordered_map<int,long long>sum;
int main(){
	int t;
	cin>>t;
	while(t--){
		sum.clear();
		int n;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;++i){
			int tmp;
			cin>>tmp;
			ans+=sum[tmp]*(n-i+1);
			sum[tmp]+=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}
