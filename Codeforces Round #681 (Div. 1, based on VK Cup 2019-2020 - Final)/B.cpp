#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[200005],b[200005],pos[200005];
bool usd[200005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			pos[a[i]]=i;
		}
		long long ans=1;
		for(int i=1;i<=m;++i){
			scanf("%d",&b[i]);
			usd[pos[b[i]]]=true;
		}
		for(int i=1;i<=m;++i){
			int now=pos[b[i]];
			long long num=0;
			if(now-1>0&&!usd[now-1])++num;
			if(now+1<=n&&!usd[now+1])++num;
			usd[now]=false;
			ans=ans*num%mod;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
