#include<bits/stdc++.h>
using namespace std;
int a[5005];
bool usd[5005];
int n;
int x[5005],y[5005],num;
void dfs(int now){
	usd[now]=true;
	for(int i=1;i<=n;++i){
		if(usd[i]||a[i]==a[now])continue;
		++num;
		x[num]=now,y[num]=i;
		dfs(i);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),usd[i]=false;
		num=0;
		dfs(1);
		if(num==n-1){
			printf("YES\n");
			for(int i=1;i<=num;++i)printf("%d %d\n",x[i],y[i]);
		}
		else printf("NO\n");
	}
	return 0;
}
