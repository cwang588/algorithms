#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+1+n);
		int now=1,ans=0;
		for(int i=1;i<=n;++i){
			while(now<=n&&a[now]<i)++now;
			if(now==n+1)break;
			ans=i;
			++now;
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	
	}
	
	return 0;
}