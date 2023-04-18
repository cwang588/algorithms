#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n;
		scanf("%I64d",&n);
		long long m=min(n-1,(n*n-1)/2);
		long long tmp=(sqrt(2*m+1)+1)/2-1;
		printf("%I64d\n",tmp);
	}
	return 0;
}
