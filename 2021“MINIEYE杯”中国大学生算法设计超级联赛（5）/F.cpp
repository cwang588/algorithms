#include<bits/stdc++.h>
using namespace std;
int cnt;
void build(int l,int r){
	++cnt;
	if(l==r)return;
	if(r==l+1){
		build(l,l);
		build(r,r);
	}
	else{
		int b=l+(r-l)/3,c=(b+r)>>1;
		build(l,b);
		build(b+1,c);
		build(c+1,r);
	}
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int tmp;
		for(int i=1;i<=n;++i)cin>>tmp;
		cnt=0;
		build(1,n);
		cout<<cnt<<endl;
	}
	return 0;
}
