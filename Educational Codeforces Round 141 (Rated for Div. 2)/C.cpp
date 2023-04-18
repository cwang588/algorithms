#include<bits/stdc++.h>
using namespace std;
int a[500005];
pair<int,int>b[500005];
bool usd[500006];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int now=0,cnt=0;
		for(int i=1;i<=n;++i)cin>>a[i],usd[i]=false,b[i]=make_pair(a[i],i);
		sort(b+1,b+1+n);
		if(b[1].first>m){
			cout<<n+1<<"\n";
			continue;
		}
		for(int i=1;i<=n;++i){
			if(now+b[i].first>m)break;
			cnt=i;
			now+=b[i].first;
			usd[b[i].second]=true;
		}
		if(cnt==n){
			cout<<"1\n";
			continue;
		}
		if(usd[cnt+1])cout<<n-cnt<<"\n";
		else{
			if(now-b[cnt].first+a[cnt+1]<=m)cout<<n-cnt<<"\n";
			else cout<<n-cnt+1<<"\n";
		}
		
	}
	
	
	return 0;
}