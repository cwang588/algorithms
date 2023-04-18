#include<bits/stdc++.h>
const double pi=3.1415926535;
using namespace std;
double calc(double r){
	return pi*r*r;
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int r,a,b;
		cin>>r>>a>>b;
		double ans=0.0;
		while(r){
			ans+=calc(r)+calc(r*a);
			r=r*a/b;
		}
		printf("Case #%d: %.8f\n",Case,ans);
	}
	
	return 0;
}