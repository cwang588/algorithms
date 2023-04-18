#include<bits/stdc++.h>
using namespace std;
const double eps=1e-10;
double a[100005],tmp[100005];
bool check(int n,int x,double m){
	for(int i=1;i<=n;++i)tmp[i]=a[i]-m;
	for(int i=1;i<=n;++i)tmp[i]+=tmp[i-1];
	double Min=100000;
	for(int i=x;i<=n;++i){
		Min=min(Min,tmp[i-x]);
		if(tmp[i]-Min>=0)return true;
	}
	return false;
}
double calc(int n,int x){
	for(int i=1;i<=n;++i)cin>>a[i];
	double l=-100000,r=100000;
	while(r-l>=eps){
		double m=(l+r)*0.5;
		if(check(n,x,m))l=m;
		else r=m;
	}
	return l;
}
int main(){
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	printf("%.10lf\n",calc(n,x)+calc(m,y));	
	return 0;
}
