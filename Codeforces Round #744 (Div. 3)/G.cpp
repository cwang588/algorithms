#include<bits/stdc++.h>
using namespace std;
int a[1000005],tmp[2000005];
bool usd[1000005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;++i)cin>>a[i],usd[i]=false;
		bool ky=true;
		for(int i=1;i<=n;++i){
			if(usd[i])continue;
			int now=i,num=0;
			while(!usd[now]){
				usd[now]=true;
				tmp[++num]=a[now];
				now+=d;
				if(now>n)now-=n;
			}
			for(int i=1;i<=num;++i)tmp[i+num]=tmp[i];
			int nownum=0,Max=0;
			for(int i=1;i<=num*2;++i){
				if(!tmp[i])Max=max(Max,nownum),nownum=0;
				else ++nownum;
			}
			Max=max(Max,nownum);
			if(Max>=num){
				cout<<"-1\n";
				ky=false;
				break;
			}
			ans=max(Max,ans);
		}
		if(ky)cout<<ans<<"\n";
	}
	return 0;
}
