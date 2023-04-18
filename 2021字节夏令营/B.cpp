#include<bits/stdc++.h>
using namespace std;
int a[105][105],dis[105][105],re[105],n,m;
bool usd[105][105],ans[105],sb[105],col[105];
void dfs(int now){
	col[now]=true;
	for(int i=1;i<=n;++i){
		if(!a[now][i])continue;
		if(!ans[i]||col[i])continue;
		dfs(i);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j])dis[i][j]=1;
			else dis[i][j]=114514;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		cin>>re[i];
		++re[i];
		sb[re[i]]=true;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(!a[i][j])continue;
			for(int k=1;k<=m;++k){
				for(int o=1;o<=m;++o){
					if(dis[i][re[k]]+dis[j][re[o]]+1==dis[re[k]][re[o]])usd[i][j]=true;
				}
			}
		}
	}
	int num=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(usd[i][j]){
				ans[i]=ans[j]=true;
			}
		}
	}
	for(int i=1;i<=n;++i)if(ans[i])++num;
	for(int i=1;i<=n;++i){
		if(sb[i]||!ans[i])continue;
		memset(col,0,sizeof(col));
		ans[i]=false;
		dfs(re[1]);
		int colcnt=0;
		for(int j=1;j<=n;++j)if(col[j])++colcnt;
		if(colcnt==num-1)--num;
		else ans[i]=true;
	} 
	printf("%d\n",num);
	return 0;
}
