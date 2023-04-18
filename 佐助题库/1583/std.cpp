#include<bits/stdc++.h>
using namespace std;
int calc(int n){
	int re=1;
	for(int i=1;i<=n;++i)re*=i;
	return re;
}
int main(){
//	freopen("10.in","w",stdout);
	int n;
	scanf("%d",&n);
//	printf("%d\n",n);
//	freopen("10.out","w",stdout);
	printf("%d\n",calc(n));
	return 0;	
}
