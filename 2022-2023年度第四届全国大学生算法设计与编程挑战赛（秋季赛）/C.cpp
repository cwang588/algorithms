#include<bits/stdc++.h>
using namespace std;
bool check(int x,int k){
	if(x==1)return false;
	for(int i=2;i*i<=x;++i)if(x%i==0)return false;
	while(x){
		if(x%10==k)return false;
		x/=10;
	}
	return true;
}
int main(){
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;++i){
		if(check(i,k))++ans;
	}
	cout<<ans<<"\n";
	return 0;
}