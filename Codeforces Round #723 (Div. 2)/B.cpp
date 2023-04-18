#include<bits/stdc++.h>
using namespace std;
bool dp[10005];
int tmp[]={11,111,1111,11111,111111,1111111,11111111};
int main(){
	dp[0]=true;
	for(int i=1;i<=10000;++i){
		for(int j=0;j<=6;++j)if(i>=tmp[j])dp[i]|=dp[i-tmp[j]];
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		if(x>10000)printf("YES\n");
		else{
			if(dp[x])printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
