#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int x=0,y=0;
	for(int i=1;i<=n;++i){
		int t;
		cin>>t;
		x=max(x,t);
	}
	for(int i=1;i<=m;++i){
		int t;
		cin>>t;
		y=max(y,t);
	}
	if(x==y)cout<<"possible\n";
	else cout<<"impossible\n";
	return 0;
}