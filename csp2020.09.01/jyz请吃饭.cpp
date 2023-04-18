#include<bits/stdc++.h>
using namespace std;
const double xl=73.66,xr=135.05,yu=53.55,yd=3.86;
int main(){
	freopen("INPUT.DAT","w",stdout);
	for(double i=xl;i<=xr+0.5;i+=0.5){
		for(double j=yd;j<=yu+0.5;j+=0.5)printf("%.2f %.2f\n",i>xr?xr:i,j>yu?yu:j);
	}
	return 0;
}
