#include<bits/stdc++.h>
using namespace std;
bool usd[1000005];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		int tmp;
		cin>>tmp;
		usd[tmp]=true;
	}
	int ans=0;
	for(int i=1;i<=1000000;++i){
		int now=0;
		if(usd[i])continue;
		for(int j=1;j*i<=1000000;++j){
			if(usd[i*j])now=gcd(now,j);
		}
		if(now==1)++ans;
	}
	cout<<ans<<"\n";
	return 0;
}