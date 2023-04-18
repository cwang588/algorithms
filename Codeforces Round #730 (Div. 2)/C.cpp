#include<bits/stdc++.h>
using namespace std;
const double eps=0.000000001;
double ans;
void dp(double c,double m,double p,double v,double now,int depth){
	if(abs(p-1.0)<eps){
		ans+=now*depth;
//		cout<<now*depth<<endl;
		return;
	}
	ans+=now*p*depth;
//	cout<<now*depth*p<<endl;
	if(c>0){
		if(c<v){
			if(abs(m)>=eps)dp(0.0,m+c*0.5,p+c*0.5,v,now*c,depth+1);
			else dp(0.0,m,p+c,v,now*c,depth+1);
		}
		else{
			if(abs(m)>=eps)dp(c-v,m+v*0.5,p+v*0.5,v,now*c,depth+1);
			else dp(c-v,m,p+v,v,now*c,depth+1);
		}
	}
	if(m>0){
		if(m<v){
			if(abs(c)>=eps)dp(c+m*0.5,0.0,p+m*0.5,v,now*m,depth+1);
			else dp(c,0.0,p+m,v,now*m,depth+1);
		}
		else{
			if(abs(c)>=eps)dp(c+v*0.5,m-v,p+v*0.5,v,now*m,depth+1);
			else dp(c,m-v,p+v,v,now*m,depth+1);
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		double c,m,p,v;
		cin>>c>>m>>p>>v;
		ans=0;
		dp(c,m,p,v,1,1);
		printf("%.8lf\n",ans);
	}
	return 0; 
} 
