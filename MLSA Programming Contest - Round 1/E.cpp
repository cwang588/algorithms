#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
int main(){
	long long n,m;
	cin>>n>>m;
	long long g=gcd(n,m),x=n/g,y=m/g;
	if(x>y)swap(x,y);
	long long ans=x+y-1;
	cout<<ans*g;
	return 0;
}
