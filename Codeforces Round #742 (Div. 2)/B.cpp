#include<bits/stdc++.h>
using namespace std;
int yh[500005];
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=300000;++i)yh[i]=yh[i-1]^i;
	while(t--){
		int a,b;
		cin>>a>>b;
		int ans=a;
		if((yh[a-1]^b)==a)ans+=2;
		else if(yh[a-1]^b)ans++;
		else;
		cout<<ans<<"\n";
	}
	
	
	return 0;
}
