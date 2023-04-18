#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+1+n);
		int cnt=0;
		for(int i=1;i<=n;++i)if(a[i]!=a[i-1])++cnt;
		for(int i=1;i<=n;++i)cout<<cnt+max(0,i-cnt)<<" ";
		cout<<"\n";
	}
	
	
	return 0;
}