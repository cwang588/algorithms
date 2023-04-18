#include<bits/stdc++.h>
using namespace std;
int f[20];
int main(){
	f[0]=f[1]=1;
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;++i)f[i]=f[i-1]+f[i-2];
	printf("%d\n",f[n]);
	return 0;
}
