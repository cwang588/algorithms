#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	int n;
	cin>>n;
	long long tot=0,ans=0;
	for(int i=1;i<=n;++i)cin>>a[i],tot+=a[i];
	int now=0;
	tot-=a[1];
	for(int i=2;i<=n;++i){
		if(tot>=0){
			++now;
			ans+=a[i]*now;
		}
		else now=0;
		tot-=a[i];
	}
	cout<<ans<<"\n";
	return 0;
}