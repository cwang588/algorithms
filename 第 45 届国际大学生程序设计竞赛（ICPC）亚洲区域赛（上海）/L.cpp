#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
double dis(long long x,long long y){
	return sqrt(x*x+y*y);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,m;
		cin>>n>>m;
	//	++n,++m;
		if(gcd(n,m)==1){
			printf("%.8lf\n",dis(n,m));
			continue;
		}
		double ans=191981011466.0;
		for(int i=0;i<=n;++i){
			long long now=m*i/n;
			for(int j=-50;j<=50;++j){
				if(now+j<0||now+j>m)continue;
				if(gcd(i,now+j)==1&&gcd(n-i,m-now-j)==1&&m*i!=n*(now+j))ans=min(ans,dis(i,now+j)+dis(n-i,m-now-j));
			}
		}
		printf("%.8lf\n",ans);
	}
	return 0;
}
