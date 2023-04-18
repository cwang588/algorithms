#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool check(int n,int del){
	vector<int>tmp;
	tmp.push_back(0);
	for(int i=1;i<=n;++i)if(a[i]!=del)tmp.push_back(a[i]);
	if(!tmp.size())return true;
	int m=tmp.size();
	for(int i=1;i*2<m;++i)if(tmp[i]!=tmp[m-i])return false;
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		int todel1=0,todel2=0;
		for(int i=1;i*2<=n;++i){
			if(a[i]!=a[n-i+1]){
				todel1=a[i];
				todel2=a[n-i+1];
				break;
			}
		}
		if(!todel1){
			cout<<"YES\n";
			continue;
		}
		if(check(n,todel1)||check(n,todel2))cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}