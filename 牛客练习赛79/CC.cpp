#include<bits/stdc++.h>
using namespace std;
long long GCD(long long x, long long y){
    if (!y) return 1ll;
    return GCD(y, x % y) + 1ll;
}
long long maxGCD(long long n) {
    long long ans = 0ll;
    for (long long i = 1; i <= n; i++)
        for (long long j = 1; j <= n; j++)
            ans = max(ans, GCD(i, j));
    return ans;
}
int main(){
	for(int i=1;i<=100;++i)printf("%d:%d\n",i,maxGCD(i));
	return 0;
}
