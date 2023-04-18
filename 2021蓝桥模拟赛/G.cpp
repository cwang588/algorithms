#include<bits/stdc++.h>
#include<string>
using namespace std;
map<string,long long>m;
void work(string s,long long tmp){
	bool a,b,c;
	a=b=c=false;
	for(int i=0;i<s.length();++i){
		if(s[i]=='A')a=true;
		if(s[i]=='B')b=true;
		if(s[i]=='C')c=true;
	}
	if(a&&b&&c)m["ABC"]=min(m["ABC"],tmp);
	if(a&&b&&!c)m["AB"]=min(m["AB"],tmp);
	if(a&&!b&&c)m["AC"]=min(m["AC"],tmp);
	if(!a&&b&&c)m["BC"]=min(m["BC"],tmp);
	if(a&&!b&&!c)m["A"]=min(m["A"],tmp);
	if(!a&&b&&!c)m["B"]=min(m["B"],tmp);
	if(!a&&!b&&c)m["C"]=min(m["C"],tmp);
}
int main(){
	int n;
	cin>>n;
	m["ABC"]=m["AB"]=m["AC"]=m["BC"]=m["A"]=m["B"]=m["C"]=2147483647;
	for(int i=1;i<=n;++i){
		long long tmp;
		string s;
		cin>>tmp>>s;
		work(s,tmp);
	}
	long long ans=21474836477777;
	ans=min(ans,m["ABC"]);
	ans=min(ans,m["AB"]+m["C"]);
	ans=min(ans,m["AC"]+m["B"]);
	ans=min(ans,m["BC"]+m["A"]);
	ans=min(ans,m["A"]+m["B"]+m["C"]);
	ans=min(ans,m["AB"]+m["BC"]);
	ans=min(ans,m["AB"]+m["AC"]);
	ans=min(ans,m["AC"]+m["BC"]);
	printf("%lld\n",ans);
	return 0;
}
