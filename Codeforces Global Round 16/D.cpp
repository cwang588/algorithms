#include<bits/stdc++.h>
using namespace std;
int a[305];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=m;++i)cin>>a[i];
		int ans=0;
		for(int i=1;i<=m;++i){
			for(int j=1;j<i;++j){
				if(a[j]<a[i])++ans;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
