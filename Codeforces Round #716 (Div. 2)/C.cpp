#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int ans[100005],cnt;
int main(){
	int n;
	scanf("%d",&n);
	long long tot=1;
	for(int i=1;i<n;++i){
		if(gcd(i,n)==1){
			ans[++cnt]=i;
			tot=tot*i%n;
		}
	}
	if(tot!=1)--cnt;
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)printf("%d ",ans[i]);
	printf("\n");
	return 0;
} 
