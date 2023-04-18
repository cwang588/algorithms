#include<bits/stdc++.h>
using namespace std;
vector<int>a[10];
int calc(int x){
	int Max=-1,Min=11;
	while(x){
		int now=x%10;
		x/=10;
		Max=max(Max,now);
		Min=min(Min,now);
	}
	return Max-Min;
}
int main(){
	for(int i=1;i<=1000000;++i)a[calc(i)].push_back(i);
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		for(int i=9;i>=0;--i){
			int now=lower_bound(a[i].begin(),a[i].end(),l)-a[i].begin();
			if(now!=a[i].size()&&a[i][now]<=r){
				cout<<a[i][now]<<"\n";
				break;
			}
		}
	}
	
	return 0;
}
