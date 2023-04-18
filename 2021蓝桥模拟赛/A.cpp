#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int ans=0;
	for(int i=1;i<=2020;++i)if(gcd(i,2020)==1)++ans;
	printf("%d",ans);
	return 0;
} 
