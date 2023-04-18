#include<bits/stdc++.h>
using namespace std;
int a[500005];
vector<int>pos[10005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],pos[a[i]].push_back(i);
	int ans=0,now=0;
	for(int i=10000;i>=1;--i){
		for(auto x:pos[i]){
			if(a[x-1]<i){
				if(a[x+1]<=i)++now;
				else;
			}
			else{
				if(a[x+1]>i)--now;
			}
		}
		ans=max(now,ans);
	}
	cout<<ans<<"\n";
	return 0;
}