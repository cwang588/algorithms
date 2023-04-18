#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 1; i <= n; ++i)
class llp
{
    int v;
    template <class T>
    static llp llrp(T a) { llp x; x.v = a; return x; }

public:
    static const int p = 998857459;
    static const int phi = 460 * 772 * 2802;
    llp() { v = 0; }
    template <class T>
    static T mod(T a) { return a > 0 ? a % p : a % p + p; }
    template <class T>
    static T &opmod(T &a) { return a = mod(a); }
    template <class T>
    llp(T a) { v = mod(a); }
    template <class T>
    explicit operator T() const { return v; }
    int operator*() const { return v; }
    int *operator&() const { return (int *)&v; }
    friend istream &operator>>(istream &ipt, llp &x) { return ipt >> x.v, opmod(x.v), ipt; }
    friend ostream &operator<<(ostream &opt, llp x) { return opt << x.v; }
    llp operator+(llp b) const { return v + b.v >= p ? llrp(v + b.v - p) : llrp(v + b.v); }
    friend llp operator+(ll a, llp b) { return b + a; }
    llp &operator+=(llp b) { return *this = *this + b; }
    llp &operator++() { return *this += 1; }
    llp operator++(int) { return ++*this, *this - 1; }
    llp operator-() const { return llrp(p - v); }
    llp operator-(llp b) const { return *this + (-b); }
    friend llp operator-(ll a, llp b) { return -b + a; }
    llp &operator-=(llp b) { return *this = *this - b; }
    llp &operator--() { return *this -= 1; }
    llp operator--(int) { return --*this, *this + 1; }
    llp operator*(llp b) const { return ll(v) * b.v; }
    friend llp operator*(ll a, llp b) { return b * a; }
    llp &operator*=(llp b) { return *this = *this * b; }
    llp operator[](ll b) const
    {
        if (!v)
            return 0;
        b = b > 0 ? b % phi : b % phi + phi;
        llp ans = 1, a = *this;
        while (b)
        {
            if (b & 1)
                ans *= a;
            a *= a, b >>= 1;
        }
        return ans;
    }
    llp operator^(ll b) const { return (*this)[b]; }
    llp &operator^=(ll b) { return *this = *this ^ b; }
    llp operator~() const { return *this ^ -1; }
    llp operator/(llp b) const { return *this * ~b; }
    llp &operator/=(llp b) { return *this = *this / b; }
    llp operator<<(int b) const { return *this * (1 << b); }
    llp &operator<<=(int b) { return *this = *this << b; }
    llp operator>>(int b) const { return *this / (1 << b); }
    llp &operator>>=(int b) { return *this = *this >> b; }
    bool operator==(ll b) const { return mod(b) == v; }
    bool operator!=(ll b) const { return !(*this == b); }
    bool operator<(llp b) const { return v < b.v; }
    bool operator<=(llp b) const { return v <= b.v; }
    bool operator>(llp b) const { return v > b.v; }
    bool operator>=(llp b) const { return v >= b.v; }
    int var() const { return v; }
    int mod() const { return p; }
    llp squ() const { return *this * *this; }
    llp pow(ll b) const { return *this ^ b; }
    llp inv() const { return ~*this; }
};
llp fac[3000];
llp psum[1200000], dis[1200000], sve[1200000];
int main()
{
    fac[0] = 1;
    rep(i, 2950)
        fac[i] = fac[i - 1] * i;
    int n, m; 
    scanf("%d%d", &n, &m);
    vector<int> vars;
    rep(i, n)
    {
        int ai;
        scanf("%d", &ai);
        if (fac[ai])
            dis[i] = fac[ai], vars.push_back(i);
    }
    rep(i, n)
        psum[i] = psum[i - 1] + dis[i];
    for (int i = 0; i < vars.size(); ++i)
        for (int j = i; j < vars.size(); ++j)
        {
            int ri = vars[i], rj = vars[j];
            int len = rj - ri + 1;
            llp var = psum[rj] - psum[ri - 1];
            sve[len] = max(sve[len], var);
        }
    rep(i, n)
        sve[i] = max(sve[i], sve[i - 1]);
    rep(i, m)
    {
        int bi;
        scanf("%d", &bi);
        if (sve[n] < bi) printf("-1\n");
        else
        {
            int ans = lower_bound(sve + 1, sve + 1 + n, bi) - sve;
            printf("%d\n", ans);
        }
    }
    return 0;
}

