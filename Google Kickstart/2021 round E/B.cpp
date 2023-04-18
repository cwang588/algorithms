#include<bits/stdc++.h>
using namespace std;
long long calc(long long x,long long y,int k){
	if(x<=k||y<=k)return x*y-1;
	long long re=(x/k)*(y/k)*(1ll*k*k-1)+(x/k-1)*(y/k)+(y/k-1)*(x/k);
	if(x%k)re+=y/k;
	if(y%k)re+=x/k;
	re+=max(0ll,x*y-(x-x%k)*(y-y%k)-1);
	return re;
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,m,k;
		cin>>n>>m>>k;
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		long long ans=calc(r2-r1+1,c2-c1+1,k);
		long long ans1=0,ans2=0,ans3=0,ans4=0;
		int a=(c1==1)?0:((r2-r1)/k+1);
		int b=(c2==m)?0:((r2-r1)/k+1);
		int c=(r1==1)?0:((c2-c1)/k+1);
		int d=(r2==n)?0:((c2-c1)/k+1);
		ans1=(c1==1?0:(min(r2-1,n-r1)/k+1))+b+c+d;
		ans2=(r1==1?0:(min(c2-1,m-c1)/k+1))+b+a+d;
		ans3=(c2==m?0:(min(r2-1,n-r1)/k+1))+a+c+d;
		ans4=(r2==n?0:(min(c2-1,m-c1)/k+1))+b+c+a;
		ans+=min(min(ans1,ans2),min(ans3,ans4));
		printf("Case #%d: %lld\n",Case,ans);
	}
	
	return 0;
}