#include<bits/stdc++.h>
using namespace std;
int a[300005];
map<int,bool>m;
vector<int>ans;
int main(){
	int n;
	long long k;
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	int now=1,cnt=0;
	while(now*2<k+1)now*=2,++cnt;
	for(int i=1;i<=n;++i){
		if(!m[a[i]>>cnt]){
			ans.push_back(i);
			m[a[i]>>cnt]=true;
		}
	}
	if(ans.size()<2)cout<<"-1";
	else{
		cout<<ans.size()<<"\n";
		for(auto x:ans)cout<<x<<" ";
	}
	return 0;
}