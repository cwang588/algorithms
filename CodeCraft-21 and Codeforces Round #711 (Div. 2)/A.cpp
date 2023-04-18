#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
long long calc(long long x){
	long long re=0;
	while(x){
		re+=x%10;
		x/=10;
	}
	return re;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n;
		scanf("%I64d",&n);
		if(n%3==0)printf("%I64d\n",n);
		else{
			long long num=calc(n);
			while(gcd(num,n)==1){
				++n;
				num=calc(n);
			}
			printf("%I64d\n",n);
		}
	}
	return 0;
}
