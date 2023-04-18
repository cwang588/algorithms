#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t; scanf("%d", &t);
    while(t--)
    {
        ll n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        ll nt = (m / (n-k+1)) + 1;
        printf("%lld\n", nt * (k-1)+m+1);
    }
}
