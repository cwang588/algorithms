#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	int ans=0;
	for(int i=1;i<=2020;++i){
		for(int j=1;j<=2020;++j)if(gcd(i,j)==1)++ans;
	}
	printf("%d\n",ans);
	return 0;
}
