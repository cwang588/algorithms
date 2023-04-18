#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],c[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)c[i]=0;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)cin>>b[i];
		for(int i=1;i<=n;++i){
			if(b[i]<a[i])++c[b[i]],--c[a[i]];
		}
		for(int i=1;i<=n;++i)c[i]+=c[i-1];
		vector<int>ans;
		for(int i=1;i<=n;++i){
			bool ky=true;
			for(int j=1;j*i<=n;++j){
				if(c[j*i]){
					ky=false;
					break;
				}
			}
			if(ky)ans.push_back(i);
		}
		cout<<ans.size()<<"\n";
		for(const auto&x:ans)cout<<x<<" ";
		cout<<"\n";
	}
	
	
	return 0;
}