#include<bits/stdc++.h>
using namespace std;
int calc(int n){
	int re=0,num=0,x;
	x=n%10;
	while(n){
		++num;
		n/=10;
	}
	re+=10*(x-1);
	re+=(num+1)*num/2;
	return re;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",calc(n));
	}
	return 0;
}
