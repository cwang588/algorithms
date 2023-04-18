#include<bits/stdc++.h>
using namespace std;
char s[100005];
struct er{
	int l,r;
	const bool operator < (const er &x)const{
		if(r<x.l)return true;
		return false;
	}
};
multiset<er>ss;
int main(){
	int n;
	while(cin>>n){
		ss.clear();
		cin>>(s+1);
		int cnt=0,now=1,num=0;
		for(int i=1;i<=n;++i)if(s[i]=='0')++num;
		int tmpnum=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='0'||s[i]=='1')continue;
			while(now<=n&&s[now]!='0')++now;
			if(!num)break;
			if(now-i==1)++cnt,--num;
			else ss.insert(er{i,now}),--num,++tmpnum;
			++now;		
		}
		int ans=0;
		while(!ss.empty()){
			auto x=ss.begin();
			er tmp=*x;
			ss.erase(x);
			auto noww=ss.upper_bound(tmp);
			if(noww!=ss.end())++ans;
			else{ 
				if(cnt){
					++ans;
					--cnt;
				}
				continue;
			}
			ss.erase(noww);
		}
		ans+=cnt/2;
		printf("%d\n",ans);
	}
	return 0;
} 
