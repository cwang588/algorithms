#include<bits/stdc++.h>
using namespace std;
bool a[1000005];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		int t;
		cin>>t;
		a[t]=true;
	}
	int ans=0;
	for(int i=1;i<=1000000;++i){
		if(a[i])continue;
		int now=0;
		for(int j=2;j*i<=1000000;++j){
			if(a[i*j])now=gcd(now,i*j);
		}
		if(now==i)++ans;
	}
	cout<<ans<<"\n";
	return 0;
}