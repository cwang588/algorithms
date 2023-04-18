#include<bits/stdc++.h>
#define double long double
using namespace std;
const double eps=1e-6;
int n;
double p,s,v;
double A,B;
double f(double x){
	return A*pow(B,x*sqrt(2))+s/v*(1/x+1);
}
int main(){
	cin>>n>>p>>s>>v;
	A=n/(p*1000000000),B=log(n)/log(2);
	double l=0.0000001,r=log(1000000000000ll)/log(B);
	while(r-l>eps){
		double m1=l+(r-l)/3,m2=m1+(r-l)/3;
		if(f(m1)<f(m2))r=m2;
		else l=m1;
	}
	printf("%.7Lf %.7Lf\n",f(l),l);
	return 0;
}
