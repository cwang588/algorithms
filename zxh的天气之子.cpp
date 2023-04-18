#include<bits/stdc++.h>
using namespace std;
struct store{
	long long a,b;
}s[200005];
bool cmp(store x,store y){
	return x.b*y.a<x.a*y.b;
}
int main(){
	int n;
	long long t;
	cin>>n>>t;
	for(int i=1;i<=n;++i){
		cin>>s[i].a>>s[i].b;
		++s[i].b;
	}
	sort(s+1,s+1+n,cmp);
	int ans=0;
	long long now=0;
	for(int i=1;i<=n;++i){
		now+=now*s[i].a+s[i].b;
		if(now>t)break;
		++ans;
	}
	cout<<ans<<endl;
	return 0;
}
