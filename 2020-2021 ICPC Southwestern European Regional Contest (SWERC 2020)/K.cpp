#include<bits/stdc++.h>
using namespace std;
string s,ans;
map<string,int>now,pos;
bool judge(int len){
	if(!len)return false;
	now.clear();
	pos.clear();
	for(int i=0;i+len-1<s.size();++i){
		string tmp=s.substr(i,len);
		++now[tmp];
		pos[tmp]=i;
	}
	int minpos=2147483647;
	for(auto x:now){
		if(x.second==1)
			minpos=min(pos[x.first],minpos);
	}
	if(minpos==2147483647)return false;
	if(ans.length()==0||ans.length()>len)ans=s.substr(minpos,len);
	return true;
}
int main(){
	cin>>s;
	int n=s.size();
	int l=0,r=n;
	while(l<r-1){
		int m=(l+r)>>1;
		if(judge(m))r=m;
		else l=m;
		
	}
	cout<<ans<<endl;
	return 0;
}
