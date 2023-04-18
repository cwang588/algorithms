#include<bits/stdc++.h>
using namespace std;
int a[105][105],ans[105][105];
bool usd[105][105];
struct value{
	int num,x,y;
}v[10005];
bool cmp(value p,value q){
	return p.num<q.num;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				scanf("%d",&a[i][j]);
				ans[i][j]=0;
				int now=(i-1)*m+j;
				v[now].num=a[i][j];
				v[now].x=i;
				v[now].y=j;
				usd[i][j]=false;
			}
		}
		sort(v+1,v+1+n*m,cmp);
		for(int i=1;i<=m;++i){
			ans[v[i].x][i]=v[i].num;
			usd[v[i].x][v[i].y]=true;
		}
		for(int i=1;i<=n;++i){
			int now=1;
			for(int j=1;j<=m;++j){
				if(!ans[i][j]){
					while(usd[i][now])++now;
					ans[i][j]=a[i][now];
					++now;
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}
