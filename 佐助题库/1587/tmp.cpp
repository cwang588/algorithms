#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int a[10005],b[10005];
bool usd[10005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	int ans=n-m;
	for(int i=1;i<=m;++i){
		if(!usd[a[i]]){
			++ans;
			usd[a[i]]=true;
		}
	}
	cout<<ans;
	return 0;
}
