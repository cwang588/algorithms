#include<bits/stdc++.h>
using namespace std;
int a[5005],sum[5006],Max[5005],Maxx[5005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		for(int i=1;i<=n;++i)Max[i]=-2147483647,cin>>a[i],sum[i]=sum[i-1]+a[i];
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j)Max[j-i+1]=max(Max[j-i+1],sum[j]-sum[i-1]);
		}
		Maxx[0]=0;
		for(int i=1;i<=n;++i)Maxx[i]=max(Max[i]+x*i,Maxx[i-1]);
		Max[0]=0;
		for(int i=n-1;i>=0;--i)Max[i]=max(Max[i],Max[i+1]);
		for(int i=0;i<=n;++i)cout<<max(Maxx[i],Max[i]+x*i)<<" ";
		cout<<"\n";
	}
	
	
	return 0;
}