#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a[105];
bool lie[105],xie1[105],xie2[105];
void dfs(int now){
	if(now==n+1){
		++cnt;
		if(cnt<=3){
			for(int i=1;i<=n;++i)printf("%d ",a[i]);
			printf("\n");
		}
		return;
	}
	for(int i=1;i<=n;++i){
		//×ø±ê£º(now,i) 
		if(lie[i]==true||xie1[now-i+n]==true||xie2[now+i]==true)continue;
		a[now]=i;
		lie[i]=xie1[now-i+n]=xie2[now+i]=true;
		dfs(now+1);
		lie[i]=xie1[now-i+n]=xie2[now+i]=false;
	}
}
int main(){
	scanf("%d",&n);
	dfs(1);
	printf("%d\n",cnt);
	return 0;
}
