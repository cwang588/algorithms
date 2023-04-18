#include<bits/stdc++.h>
#define int long long
using namespace std;
int solve(int r, int n) {
    vector<int>p;
    p.clear();
    for(int i = 2; i*i <= n; ++i) {
        if(n % i == 0) {
            p.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) p.push_back(n); //可能n也是素数
    int sum = 0;
    for(int msk = 1; msk < (1<<p.size()); ++msk) {
        int mult = 1, bits = 0;
        for(int i = 0; i < p.size(); ++i) {
            if(msk & (1<<i)) { //选择了第i个素数因子 
                bits++; 
                mult *= p[i];
            }
        }
        int cur = r / mult;
        if(bits & 1) sum += cur;
        else sum -= cur;
    } 
    return r - sum;
}

signed main()
{
	long long n;
	scanf("%lld",&n);
	long long ans=0;
	for(long long i=1;i*i<=n;++i)
		ans+=solve(min(n/i,n/i),i);
	printf("%lld\n",ans);
	return 0;
}
