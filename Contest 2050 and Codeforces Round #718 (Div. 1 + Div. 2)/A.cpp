#include<bits/stdc++.h>
using namespace std;
long long a[505];
int main(){
	a[1]=2050;
	for(int i=2;i<=14;++i)a[i]=a[i-1]*10;
	int t;
	scanf("%d",&t);
	while(t--){
		long long n;
		scanf("%I64d",&n);
		int ans=0;
		if(n%2050){
			printf("-1\n");
			continue;
		}
		n/=2050;
		while(n){
			ans+=n%10;
			n/=10;
		}
		printf("%d\n",ans);
	}
	return 0;
}
