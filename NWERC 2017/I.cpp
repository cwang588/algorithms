#include<bits/stdc++.h>
using namespace std;
struct app{
	int d,s,id;
}a[505];
bool cmp(app x,app y){
	return x.d-x.s>y.d-y.s;
}
int dp[505][10005],last[505][10005],ans[505];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i].d,&a[i].s),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j){
			dp[i][j]=dp[i-1][j];
			int now=max(a[i].d,a[i].s);
			if(m-(j-a[i].s)<now||j<a[i].s)continue;
			if(dp[i][j]<dp[i-1][j-a[i].s]+1){
				dp[i][j]=dp[i-1][j-a[i].s]+1;
				last[i][j]=1;
			}
		}
	}
	int ansnum=0,now,anscnt=0;
	for(int i=0;i<=m;++i){
		if(dp[n][i]>ansnum){
			ansnum=dp[n][i];
			now=i;
		}
	}
	for(int i=n;i>=1;--i){
		if(last[i][now]){
			ans[++anscnt]=a[i].id;
			now-=a[i].s;
		}
	}
	printf("%d\n",ansnum);
	for(int i=anscnt;i>=1;--i)printf("%d ",ans[i]);
	return 0;
}
