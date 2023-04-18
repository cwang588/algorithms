#include<bits/stdc++.h>
using namespace std;
int sum[15005][55],col[15005][55],cnt[15005];
int main(){
	int n,m,c;
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=c;++j)sum[i][j]=sum[i-1][j]; 
		scanf("%d",&cnt[i]);
		for(int j=1;j<=cnt[i];++j)scanf("%d",&col[i][j]),++sum[i][col[i][j]];
	}
	for(int i=n+1;i<=n+m;++i){
		for(int j=1;j<=c;++j)sum[i][j]=sum[i-1][j];
		for(int j=1;j<=cnt[i-n];++j)++sum[i][col[i-n][j]];
	}
	int ans=0;
	for(int i=1;i<=c;++i){
		bool ky=true;
		for(int j=1;j<=n;++j){
			if(sum[j+m-1][i]-sum[j-1][i]>1){
				ky=false;
				break;
			}
		}
		if(!ky)++ans;
	}
	printf("%d\n",ans);
	return 0;
}
