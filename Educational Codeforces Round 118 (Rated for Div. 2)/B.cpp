#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int Min=19260817;
		for(int i=1;i<=n;++i)cin>>a[i],Min=min(Min,a[i]);
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(a[i]==Min)continue;
			cout<<a[i]<<" "<<Min<<"\n";
			++cnt;
			if(cnt==n/2)break;
		}
	}
	
	
	return 0;
}