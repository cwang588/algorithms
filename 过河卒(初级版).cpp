#include<bits/stdc++.h>
using namespace std;
int f[15][15];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	f[1][1]=1;
	for(int i=1;i<=n+1;++i){
		for(int j=1;j<=m+1;++j){
			if(i!=1||j!=1)f[i][j]=f[i-1][j]+f[i][j-1];
		}
	}
	printf("%d\n",f[n+1][m+1]);
	return 0;
}
