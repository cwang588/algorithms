#include<bits/stdc++.h>
using namespace std;
int cnt[2005];
int main(){
	ios::sync_with_stdio(false);
	string s;
	while(cin>>s){
		int ans=1;
		int r=-1;
		int len=s.length();
		for(int i=0;i<len-1;++i){
			if(r==len-1)break;
			while(true){
				++r;
				++cnt[s[r]];
				if(cnt[s[r]]>1){
					--cnt[s[r]];
					--r;
					break;
				}
				if(r==len-1)break;
			}
			ans=max(ans,r-i+1);
			--cnt[s[i]];
		}
		for(int i=0;i<len;++i)cnt[s[i]]=0;
		cout<<ans<<"\n";		
	}
	
	
	return 0;
}
