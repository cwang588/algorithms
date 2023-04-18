#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[2000005];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
signed main(){
    int n,m;
    cin>>n>>m;
    bool ky=true;
    for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]%2)ky=false;
		a[i]/=2;
	}
	if(!ky)return !printf("0\n");
    long long g=a[1],lcm=a[1];
	for(int i=2;i<=n;++i){
		g=gcd(lcm,a[i]);
		lcm=lcm*a[i]/g;
		if(lcm>m)return !printf("0\n");
	}
	for(int i=1;i<=n;++i){
		if((lcm/a[i])%2==0)return !printf("0\n");
	}
	cout<<(m/lcm+1)/2;
    return 0;
}