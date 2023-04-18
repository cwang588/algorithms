#include<bits/stdc++.h>
using namespace std;
char a[200005];
int num[200005];
int n;
bool check(int x){
	int now=0;
	int r=0;
	for(int i=1;i<=n;++i){
		if(i>1&&a[i-1]=='0')--now;
		while(r<n&&(a[r+1]=='1'||now<x)){
			++r;
			now+=a[r]=='0'?1:0;
		}
		if(n-num[n]-r+i-1+num[r]-num[i-1]<=x)return true;
	}
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>(a+1);
		n=strlen(a+1);
		for(int i=1;i<=n;++i){
			num[i]=num[i-1];
			if(a[i]=='0')++num[i];
		}
		int l=-1,r=n;
		while(l<r-1){
			int m=(l+r)>>1;
			if(check(m))r=m;
			else l=m;
		}
		cout<<r<<"\n";
	}
	
	return 0;
}