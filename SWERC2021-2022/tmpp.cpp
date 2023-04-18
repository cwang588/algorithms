#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],a[i]/=2;
	int ans=0;
	for(int i=1;i<=m;++i){
		bool ky=true;
		for(int j=1;j<=n;++j){
			if(i%a[j]||(i/a[j])%2==0){
				ky=false;
				break;
			}
		}
		if(ky)++ans;
	}
	cout<<ans<<"\n";	
	
	return 0;
}