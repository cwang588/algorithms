#include<bits/stdc++.h>
using namespace std;
string s[105];
int now[105],cnt[105];
char ss[6000005];
set<char>tmp;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		tmp.clear();
		for(int i=1;i<=n;++i)cin>>s[i],now[i]=0;
		for(int i=1;i<=n;++i){
			for(auto x:s[i])tmp.insert(x);
		}
		for(int i=1;i<=26;++i)cnt[i]=0;
		int tot=0,num=tmp.size();
		for(int i=1;i<=55440;++i){
			for(int j=1;j<=n;++j){
				++now[j];
				if(now[j]==s[j].length()+1)now[j]=1;
				ss[++tot]=s[j][now[j]-1];
			}
		}
		int r=0,ans=2147483647,nowcnt=0;
		for(int i=1;i<=tot;++i){
			while(r<tot&&nowcnt<num){
				++r;
				++cnt[ss[r]-'a'+1];
				if(cnt[ss[r]-'a'+1]==1)++nowcnt;
			}
			if(nowcnt<num)break;
			ans=min(ans,r-i+1);
			--cnt[ss[i]-'a'+1];
			if(cnt[ss[i]-'a'+1]==0)--nowcnt;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
