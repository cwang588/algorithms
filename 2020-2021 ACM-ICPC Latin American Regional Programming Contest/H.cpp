#include<bits/stdc++.h>
using namespace std;
int a[105][1005],cnt[105],now[105];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		if(s=="*")cin>>a[i][1],cnt[i]=-1;
		else{
			for(int j=0;j<s.length();++j)cnt[i]=cnt[i]*10+s[j]-'0';
			for(int j=1;j<=cnt[i];++j)cin>>a[i][j];
		}
	}
	int num=0,pos=1,ans=0;
	while(1){
		if(cnt[pos]==-1){
			++num;
			if(pos==1)++ans;
			pos=a[pos][1];
		}
		else{
			++now[pos];
			++num;
			if(pos==1)++ans;
			if(now[pos]>cnt[pos])break;
			pos=a[pos][now[pos]];
		}
		if(num>200000)break;
	}
	if(num<=200000)cout<<ans;
	else{
		if(cnt[1]==-1)cout<<"*";
		else cout<<ans;
	}
	return 0;
}
