#include<bits/stdc++.h>
using namespace std;
bool usd[15];
bool check(int x){
	memset(usd,0,sizeof(usd));
	int t=x;
	while(t){
		int now=t%10;
		t/=10;
		if(!now||usd[now]||x%now)return false;
		usd[now]=true;
	}
	return true;
}
int main(){
	int l,r;
	cin>>l>>r;
	int ans=0;
	for(int i=l;i<=r;++i)if(check(i))++ans;
	cout<<ans<<"\n";	
	return 0;
}