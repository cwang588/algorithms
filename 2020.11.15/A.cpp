#include<bits/stdc++.h>
using namespace std;
char ans[10005];
int main(){
	int n,m;
	string s;
	cin>>m>>s>>n;
	long long tmp=0;
	int len=s.length();
	for(int i=0;i<len;++i){
		tmp*=m;
		if(s[i]>='0'&&s[i]<='9')tmp+=s[i]-'0';
		else tmp+=s[i]-'A'+10;
	}
	int num=0;
	while(tmp){
		++num;
		long long now=tmp%n;
		if(now<=9)ans[num]='0'+now;
		else ans[num]=now-10+'A';
		tmp/=n;
	}
	for(int i=num;i>=1;--i)cout<<ans[i];
	return 0;	
}
