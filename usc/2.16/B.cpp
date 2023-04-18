#include<bits/stdc++.h>
using namespace std;
double calc(int a,int b,int c,int d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main(){
	int x,y,xx1,yy1,xx2,yy2;
	cin>>x>>y>>xx1>>yy1>>xx2>>yy2;
	double ans=1e18;
	ans=min(ans,calc(x,y,xx1,yy1));	
	ans=min(ans,calc(x,y,xx1,yy2));	
	ans=min(ans,calc(x,y,xx2,yy1));	
	ans=min(ans,calc(x,y,xx2,yy2));
	if(x>=min(xx1,xx2)&&x<=max(xx1,xx2)){
		ans=min(ans,fabs(y-yy1));	
		ans=min(ans,fabs(y-yy2));	
	}
	if(y>=min(yy1,yy2)&&y<=max(yy1,yy2)){
		ans=min(ans,fabs(x-xx1));	
		ans=min(ans,fabs(x-xx2));	
	}
	cout<<ans<<"\n";
	return 0;
}