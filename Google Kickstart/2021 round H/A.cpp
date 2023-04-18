#include<bits/stdc++.h>
using namespace std;
bool usd[30];
int ans[30];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		memset(usd,0,sizeof(usd));
		string s,f;
		cin>>s>>f;
		for(auto x:f)usd[x-'a'+1]=true;
		for(int i=1;i<=26;++i){
			int now=i,cnt=0;
			ans[i]=19260817;
			while(!usd[now]){
				++now;
				if(now>26)now-=26;
				++cnt;
			}
			ans[i]=min(ans[i],cnt);
			now=i,cnt=0;
			while(!usd[now]){
				--now;
				if(now<1)now+=26;
				++cnt;
			}
			ans[i]=min(ans[i],cnt);
		}
		int tot=0;
		for(auto x:s)tot+=ans[x-'a'+1];
		cout<<"Case #"<<Case<<": "<<tot<<"\n";
	}
	return 0;
}