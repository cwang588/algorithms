#include<bits/stdc++.h>
using namespace std;
int n,m;
int calc(int x,int y){
	return max(x-1,n-x)+max(y-1,m-y);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<int>v;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)v.push_back(calc(i,j));
		}
		sort(v.begin(),v.end());
	//	reverse(v.begin(),v.end());
		for(auto x:v)cout<<x<<" ";
		cout<<"\n";
	}
	
	
	return 0;
}