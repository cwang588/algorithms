#include<bits/stdc++.h>
using namespace std;
int a[51],dp[51][51];
int work(int n,int k){
	for(int i=1;i<=n;++i)a[i]=i;
	int re=1;
	while(next_permutation(a+1,a+1+n)){
		bool ky=true;
		for(int i=k+1;i<=n;++i){
			int mm=114514;
			for(int j=i-k;j<i;++j)mm=min(mm,a[j]);
			if(a[i]<=mm){
				ky=false;
				break;
			}
		}
		if(ky)++re;
	}
	return re;
}
int main(){
	for(int i=1;i<=10;++i){
		for(int j=1;j<=i;++j){
			printf("%d ",work(i,j));
			dp[i][j]=work(i,j);
		}
		printf("\n");
	}
	for(int i=1;i<=10;++i){
		for(int j=1;j<=i;++j){
			printf("%d ",dp[i][j]-dp[i-1][j]*i);
		}
		printf("\n");
	}
	return 0;
}
