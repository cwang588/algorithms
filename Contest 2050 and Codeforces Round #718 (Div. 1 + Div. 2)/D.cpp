#include<bits/stdc++.h>
using namespace std;
long long a[505][505],b[505][505],dp[25][505][505];
int mov[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main(){
	int n,m,K;
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;++i){
		for(int j=1;j<m;++j)scanf("%I64d",&a[i][j]);
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<=m;++j)scanf("%I64d",&b[i][j]);
	}
	if(K%2){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)printf("-1 ");
			printf("\n");
		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int xfrom=max(1,i-K/2),xto=min(i+K/2,n);
			for(int x=xfrom;x<=xto;++x){
				int yfrom=max(1,j-K/2+abs(x-i)),yto=min(m,j+K/2-abs(x-i));
				for(int y=yfrom;y<=yto;++y){
					dp[0][x][y]=2147483647114514;
				}
			}
			dp[0][i][j]=0;
			for(int k=1;k<=K;++k){
				xfrom=max(1,i-min(k,K-k)),xto=min(i+min(k,K-k),n);
				for(int x=xfrom;x<=xto;++x){
					int yfrom=max(1,j-min(k,K-k)+abs(x-i)),yto=min(m,j+min(k,K-k)-abs(x-i));
					for(int y=yfrom;y<=yto;++y){
						dp[k][x][y]=2147483647114514;
						for(int o=0;o<4;++o){
							int tox=x+mov[o][0],toy=y+mov[o][1];
							if(tox>0&&tox<=n&&toy>0&&toy<=m&&abs(tox-i)+abs(toy-j)<=min(k-1,K-k+1)){
								if(mov[o][0])dp[k][x][y]=min(dp[k][x][y],dp[k-1][tox][toy]+b[min(x,tox)][y]);
								else dp[k][x][y]=min(dp[k][x][y],dp[k-1][tox][toy]+a[x][min(y,toy)]);
							}
						}
					}
				}
			}
			printf("%I64d ",dp[K][i][j]);
		}
		printf("\n");
	}
	return 0;
}
