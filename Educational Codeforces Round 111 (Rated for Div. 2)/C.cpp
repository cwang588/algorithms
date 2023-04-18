#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool judge(int l,int r){
	for(int i=l;i<=r;++i){
		for(int j=i;j<=r;++j){
			for(int k=j;k<=r;++k){
				if(i==j||i==k||j==k)continue;
				if(abs(a[i]-a[k])+abs(i-k)==abs(a[i]-a[j])+abs(i-j)+abs(a[j]-a[k])+abs(j-k))return false;
				
			}
		}
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		int ans=2*n-1;
		for(int i=1;i<=n;++i){
			for(int j=3;j<=4;++j){
				if(i+j-1>n)continue;
				if(judge(i,i+j-1))++ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
