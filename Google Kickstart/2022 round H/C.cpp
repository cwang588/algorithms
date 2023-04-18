#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[460005],sum[540006],len[450000];
int usd[450006];
signed main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n;
		cin>>n;
		sum[0]=0;
		for(int i=1;i<=n;++i)cin>>a[i],usd[i]=0,len[i]=0;
		for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
		sum[n+1]=-2147483647;
		stack<int>s;
		s.push(n+1);
		long long ans=0;
		s.push(n);
		for(int i=n-1;i>=0;--i){
			while(sum[s.top()]>=sum[i])s.pop();
			len[i+1]=s.top()-i-1;
			++usd[s.top()];
			s.push(i);
		}
		long long now=0,mi=0;
		for(int i=1;i<=n;++i){
			now+=len[i];
			++mi;
			mi-=usd[i];
			ans+=1ll*a[i]*now;
			now-=mi;
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	
	return 0;
}