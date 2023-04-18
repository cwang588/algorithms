#include<bits/stdc++.h>
using namespace std;
long long t[205],x[205],y[205];
bool dp[205][100005];
int ans[100005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%I64d%I64d%I64d",&t[i],&x[i],&y[i]);
	for(int i=1;i<=m;++i)ans[i]=250;
	dp[0][0]=true;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(!dp[i-1][j])continue;
			dp[i][j]=true;
			long long now=j;
			for(int k=1;k<=y[i];++k){
				if(t[i]==1)now=(now*100000+x[i]-1)/100000+1;
				else now=now?(now*x[i]-1)/100000+1:0;
				if(now>m||dp[i-1][now])break;
				dp[i][now]=true;
				ans[now]=min(ans[now],i);
			}
		}
	}
	for(int i=1;i<=m;++i)printf("%d ",ans[i]==250?-1:ans[i]);
	printf("\n");
	return 0;
}
