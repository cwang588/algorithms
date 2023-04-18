#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	a[1]=a[2]=1;
	for(int i=3;i<=100;++i){
		a[i]=a[i-1]+a[i-2];
		a[i]%=2;
	}
	for(int i=1;i<=100;++i)printf("%d:%d\n",i,a[i]);
	return 0;
} 
