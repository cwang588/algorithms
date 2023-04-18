#include<bits/stdc++.h>
using namespace std;
int a[5005][5005];
int main(){
	for(int i=0;i<=20;++i)a[i][0]=1;
	for(int i=1;i<=20;++i){
		for(int j=1;j<=i;++j)a[i][j]=(a[i-1][j]+a[i-1][j-1])%2;
	}
	for(int i=0;i<=20;++i){
		for(int j=0;j<=i;++j)printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
