#include<bits/stdc++.h>
using namespace std;
double calc(double h){
	return 2*3.1415926*3*3*h/3;
}
bool check(double h){
	return h*100-calc(h)*2>=400;
}
int main(){
	double l=0,r=6;
	while(r-l>0.01){
		double m=(r+l)/2;
		if(check(m))r=m;
		else l=m;
	}
	cout<<r;
	return 0;
}