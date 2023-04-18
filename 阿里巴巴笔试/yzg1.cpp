#include<bits/stdc++.h>
using namespace std;
double f(double x){
	if(x<1.0)return x;
	if(x<10.0)return x*2.0-1;
	return x*3.0-11.0;
}
int main(){
	double x;
	cin>>x;
	cout<<f(x)<<"\n";
	return 0;
}
