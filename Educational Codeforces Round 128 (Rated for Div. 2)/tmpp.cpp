#include<bits/stdc++.h>
using namespace std;
bool check(long long x){
	double a=800000,b=10000,c=x;
	for(int i=1;i<=210;++i){
		a-=(b-c);
		if(a<=0)return true;
		a=a*(1+0.0392207);
		b=b*(1+0.03);
		c=c*(1+0.01980263);
	}
	return false;
}
int main(){
	int l=0,r=6003;
	while(l<r-1){
		int m=(r+l)>>1;
		if(check(m))l=m;
		else r=m;
	}
	cout<<l;
	return 0;
}