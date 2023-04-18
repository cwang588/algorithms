#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long ans=0,last=0,now;
	while(n--){
		cin>>now;
		ans+=max(1ll*0,now-last);
		last=now;
	}
	cout<<ans<<endl;
	return 0;
}
