#include<bits/stdc++.h>
using namespace std;
long long n;
bool check(long long x){
	long long a=x/3,b=x/3,c=x/3;
	x%=3;
	if(x)++a,--x;
	if(x)++b;
	return (a*b+a*c+c*b)*2>=n;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int l=0,r=10000000;
		while(l<r-1){
			int m=(l+r)>>1;
			if(check(m))r=m;
			else l=m;
		}
		cout<<r<<"\n";
	}
	
	return 0;
}