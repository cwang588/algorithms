#include<bits/stdc++.h>
using namespace std;
int n;
int ans[10005];
void dfs(int now,int re,int last){
	if(re==0){
		if(now==2)return;
		for(int i=1;i<now-1;++i)printf("%d+",ans[i]);
		printf("%d\n",ans[now-1]);
		return;
	}
	if(re<last)return;
	for(int i=last;i<=re;++i){
		ans[now]=i;
		dfs(now+1,re-i,i);
	}
}
int main(){
	scanf("%d",&n);
	dfs(1,n,1);
	return 0;
} 
