#include<bits/stdc++.h>
using namespace std;
char s[5005];
int main(){
	int n;
	cin>>n>>(s+1);
	long long ans=0;
	for(int i=1;i<=n;++i){
		ans+=i*(n-i+1);
		for(int j=1;j<=n;++j){
			if(i-j<=0||i+j>n||s[i-j]!=s[i+j])break;
			ans+=(i-j)*(n-i-j+1);
		}
	}
	for(int i=1;i<n;++i){
		if(s[i]!=s[i+1])continue;
		ans+=i*(n-i);
		for(int j=1;j<=n;++j){
			if(i-j<=0||i+j+1>n||s[i-j]!=s[i+j+1])break;
			ans+=(i-j)*(n-i-j);
		}
	}
	cout<<ans;
	return 0;
}