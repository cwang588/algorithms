#include<bits/stdc++.h>
using namespace std;
struct mouse{
	int x,y,t;
}a[25];
int n;
double c;
double dp[40005][20];
double v[25];
double calc(int xx1,int yy1,int xx2,int yy2,double nowc){
	double dis=sqrt((xx2-xx1)*(xx2-xx1)+(yy2-yy1)*(yy2-yy1));
	return dis/nowc;
}
bool check(double m){
	v[0]=m;
	for(int i=1;i<=n;++i)v[i]=v[i-1]*c;
	for(int i=1;i<(1<<n);++i){
		for(int j=0;j<n;++j)dp[i][j]=1e10;
	}
	dp[0][0]=0;
	for(int i=1;i<(1<<n);++i){
		int cnt=0;
		for(int j=0;j<n;++j){
			if(i&(1<<j))++cnt;
		}
		for(int j=0;j<n;++j){
			if(i&(1<<j)){
				int now=i^(1<<j);
				if(!now){
					double ti=calc(0,0,a[j].x,a[j].y,v[cnt-1]);
					if(ti<=a[j].t)dp[i][j]=ti;
				}else{
					for(int k=0;k<n;++k){
						if(now&(1<<k)){
							double ti=calc(a[k].x,a[k].y,a[j].x,a[j].y,v[cnt-1])+dp[now][k];
							if(ti<=a[j].t)dp[i][j]=min(dp[i][j],ti);
						}
					}
				}
			}
		}
	}
	for(int i=0;i<n;++i){
		if(dp[(1<<n)-1][i]<=a[i].t)return true;
	}
	return false;
}
int main(){
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i].x>>a[i].y>>a[i].t;
	char t;
	int cc;
	cin>>t>>cc;
	c=1.0*cc/100;
	if(n==0){
		cout<<"0.0000000000\n";
		return 0;
	}
	double l=0.0,r=1e8;
	while(r-l>1e-7){
		double m=(l+r)/2;
		if(check(m))r=m;
		else l=m;
	}
	printf("%.16f\n",r);
	return 0;
}