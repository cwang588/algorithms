#include<bits/stdc++.h>
using namespace std;
long long a[1005];
int main(){
	a[0]=0;
	a[1]=1;
	for(int i=2;i<=60;++i)a[i]=a[i-1]+a[i-2];
	int n;
	cin>>n;
	while(n--){
		int t;
		cin>>t;
		printf("Fib(%d) = %lld\n",t,a[t]);
	}
	return 0;
}
