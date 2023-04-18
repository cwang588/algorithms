#include<bits/stdc++.h>
using namespace std;
const double inf=2147483647;
double calc(long long W,long long H,long long X1,long long Y1,long long X2,long long Y2,long long w,long long h){
	if(w>W||h>H)return inf;
	if(w>W-X2+X1&&h>H-Y2+Y1)return inf;
	if((w<X1||w<W-X2)&&(h<Y1||h<H-Y2))return 0;
	double re=inf;
	if(w<=W-X2+X1)re=min(re,1.0*min(max(w-X1,1ll*0),max(w-W+X2,1ll*0)));
	if(h<=H-Y2+Y1)re=min(re,1.0*min(max(h-Y1,1ll*0),max(h-H+Y2,1ll*0)));
	//return min(w-X1,min(w-W+X2,min(h-Y1,h-H+Y2)));
	return re;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long W,H,X1,X2,Y1,Y2,w,h;
		cin>>W>>H>>X1>>Y1>>X2>>Y2>>w>>h;
		double ans=calc(W,H,X1,Y1,X2,Y2,w,h);
		if(ans==inf)cout<<"-1\n";
		else printf("%.8lf\n",ans);
	}
	
	return 0;
}
