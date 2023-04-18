#include<bits/stdc++.h>
using namespace std;
long long fac[25],C[25][25];
void init(){
	fac[0]=1;
	for(int i=1;i<=20;++i)fac[i]=fac[i-1]*i;
	for(int i=0;i<=20;++i)C[i][0]=1;
	for(int i=1;i<=20;++i){
		for(int j=1;j<=i;++j)C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
}
int main(){
	init();
	int n;
	scanf("%d",&n);
	printf("%I64d\n",fac[n/2-1]*fac[n/2-1]*C[n][n/2]/2);
	return 0;
}
