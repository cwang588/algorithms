#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
		for(int i=0;i<n;++i){
			if(a[i]=='0'){
				if(b[i]=='0')++cnt1;
				else ++cnt2;
			}
			else{
				if(b[i]=='0')++cnt3;
				else ++cnt4;
			}
		}
		int ans=2147483647;
		if(cnt4==cnt1+1)ans=min(ans,cnt4+cnt1);
		if(cnt2==cnt3)ans=min(ans,cnt2+cnt3);
		if(ans==2147483647)cout<<"-1\n";
		else cout<<ans<<'\n';
	}
	
	
	return 0;
}