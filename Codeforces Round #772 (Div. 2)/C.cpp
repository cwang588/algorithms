#include<bits/stdc++.h>
using namespace std;
int a[200005];
struct op{
	int x,y,z;
};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		bool ky=true;
		vector<op>ans;
		for(int i=n-1;i>=1;--i){
			if(a[i]>a[i+1]){
				ky=false;
				break;
			}
			if(a[i]-a[n]<=a[i]){
				for(int j=1;j<i;++j)ans.push_back(op{j,i,n});
				break;
			}
		}
		if(ky){
			cout<<ans.size()<<"\n";
			for(auto bkx:ans)cout<<bkx.x<<" "<<bkx.y<<" "<<bkx.z<<"\n";
		}
		else cout<<"-1\n";
	}
	
	
	return 0;
}