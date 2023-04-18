#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		if(n==1){
			cout<<a[1]<<"\n";
			continue;
		}
		bool ky=false;
		for(int i=1;i<=n;++i){
			if(a[i]!=i){
				int now=i;
				while(a[now]!=i)++now;
				for(int j=1;j<i;++j)cout<<a[j]<<" ";
				for(int j=now;j>=i;--j)cout<<a[j]<<" ";
				for(int j=now+1;j<=n;++j)cout<<a[j]<<" ";
				cout<<"\n";
				ky=true;
				break;
			}
		}
		if(!ky){
			for(int i=1;i<=n;++i)cout<<a[i]<<" ";
			cout<<"\n";
		}
	}
	
	
	return 0;
}