#include<bits/stdc++.h>
using namespace std;
char s[1005],trans[35];
int last[35];
int main(){
	int n;
	cin>>n>>s+1;
	string ans;
	for(int i=1;i<=n;++i){
		last[s[i]-'a'+1]=i;
		for(int j=1;j<=26;++j){
			int cnt=0;
			for(int k=1;k<=26;++k){
				if(last[k]>last[j])++cnt;
			}
			trans[j]='a'+cnt;
		}
		string now;
		for(int j=1;j<=i;++j)now+=trans[s[j]-'a'+1];
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}