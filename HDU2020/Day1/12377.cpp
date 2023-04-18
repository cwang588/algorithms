#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ullong;
int t, k, a, aj;
ullong gcd(ullong a, ullong b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
    ullong lcm = 1;
    scanf("%d%d", &k, &a);
    for (int j = 0; j < k; j++)
        scanf("%d", &aj),
        lcm = lcm / gcd(lcm, aj) * aj;
    printf("%llu\n", lcm - a);
    return 0;
}
