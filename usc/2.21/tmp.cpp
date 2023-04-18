#include<bits/stdc++.h>
using namespace std;
int calc(int x){
	int re=0;
	while(x){
		re+=x%10;
		x/=10;
	}
	return re;
}
int main(){
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;++i)ans+=calc(i);
	cout<<ans<<"\n";
	
	return 0;
}