#include<bits/stdc++.h>
using namespace std;
struct point{
	int now,tot;
	friend bool operator <(const point &a,const point &b){
		if(a.tot!=b.tot)return a.tot<b.tot;
		return a.now<b.now;
	}
};
int a[1000006],value[1000006];
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=k;++i)value[i]=10000;
		for(int i=1;i<=n;++i)cin>>a[i];
		int ans=19260817;
		for(int i=n;i>=1;--i){
			int now=0;
			for(int j=i;j>=1;--j){
				now+=a[j];
				if(now>k)break;
				ans=min(ans,i-j+1+value[k-now]);
			}
			now=0;
			for(int j=i;j<=n;++j){
				now+=a[j];
				if(now>k)break;
				value[now]=min(value[now],j-i+1);
			}
		}
		cout<<"Case #"<<Case<<": ";
		if(ans>n)cout<<"-1\n";
		else cout<<ans<<"\n";
	}
	
	return 0;
}