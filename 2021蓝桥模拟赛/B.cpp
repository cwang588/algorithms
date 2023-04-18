#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	int v,p;
	v=1160,p=2021;
	a[1]=v;
	int now=1;
	while(a[now]){
		a[now+1]=p%a[now];
		++now;
	}
	printf("%d\n",now);
	return 0;
} 
