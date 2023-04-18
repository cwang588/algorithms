#include<bits/stdc++.h>
using namespace std;
int num[200005][25];
int main(){
	for(int i=1;i<=200000;++i){
		int now=0,x=i;
		while(x){
			num[i][now]+=x&1;
			x>>=1;
			++now;
		}
		for(int j=0;j<=20;++j)num[i][j]+=num[i-1][j];
	}
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		int ans=2147483647;
		for(int i=0;i<=20;++i)ans=min(ans,r-l+1-num[r][i]+num[l-1][i]);
		cout<<ans<<"\n";
	}
	
	return 0;
}