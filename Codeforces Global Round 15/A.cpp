#include<bits/stdc++.h>
using namespace std;
char s[1005],tmp[1005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n>>(s+1);
		for(int i=1;i<=n;++i)tmp[i]=s[i];
		sort(s+1,s+1+n);
		int ans=0;
		for(int i=1;i<=n;++i)if(s[i]!=tmp[i])++ans;
		cout<<ans<<endl;
	}
	return 0;
}
