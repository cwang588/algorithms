#include<bits/stdc++.h>
using namespace std;
int a[100005],num;
int lowbit(int x){
	return x&(-x);
}
int main(){
	int n;
	scanf("%d",&n);
	if(n%2)return !printf("-1\n");
	while(n){
		a[++num]=lowbit(n);
		n-=lowbit(n);
	}
	for(int i=num;i>=1;--i)printf("%d ",a[i]);
	printf("\n");
	return 0;
}
