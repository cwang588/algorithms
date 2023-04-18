#include<bits/stdc++.h>
using namespace std;
const double eps=1e-7;
double a,b,c,d,e;
double f(double x){
	return a*x*x*x+b*x*x+c*x+d+e*sin(x);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d>>e;
		if(f(0)>eps||f(1)<-eps)cout<<"No solution\n";
		else{
			double l=0,r=1;
			while(l<r-eps){
				double m=(l+r)*0.5;
				if(f(m)<0)l=m;
				else r=m;
			}
			printf("%.4lf\n",r);
		}
	}
	return 0;
}
