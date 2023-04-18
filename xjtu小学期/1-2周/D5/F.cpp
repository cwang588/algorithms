#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL maxn=4e5+5, maxm=105, mod=1e9+7;
LL n, q, m, a[maxn], b[maxm], f[maxm][maxm];
LL fac[maxn], inv[maxn], pre[maxn];
inline int min(LL x, LL y){ return x<y?x:y; }

LL C(LL x, LL y){ return fac[x]*inv[y]%mod*inv[x-y]%mod; }

LL fpow(LL a, LL x){
    LL ans=1, base=a;
    for (; x; x>>=1, base*=base, base%=mod)
        if (x&1) ans*=base, ans%=mod;
    return ans;
}

int getint(){
    char c; int flag=1, re=0;
    for (c=getchar(); !isdigit(c); c=getchar())
        if (c=='-') flag=-1;
    for (re=c-48; c=getchar(), isdigit(c); re=re*10+c-48);
    return re*flag;
}

int main(){
    scanf("%lld%lld", &n, &q); 
    fac[0]=1; inv[0]=1;
    for (LL i=1; i<maxn; ++i) fac[i]=(i*fac[i-1])%mod, inv[i]=fpow(fac[i], mod-2);
    for (LL i=1; i<=n; ++i) scanf("%lld", &a[i]);
        memset(b, 0, sizeof(b));
        memset(f, 0, sizeof(f));
        m=getint();
        for (LL i=1; i<=n; ++i) ++b[(a[i]%m+m)%m];
        f[0][0]=fpow(2, b[0]);
        for (LL i=1; i<m; ++i){  //第几个桶 
            for (LL j=0; j<=b[i]; ++j){
                if (j<m) pre[j%m]=0;
                (pre[j%m]+=C(b[i], j))%=mod;
            }
            for (LL w=0; w<m; ++w)  //所有数的和的余数是w 
                for (LL j=0; j<=min(m-1, b[i]); ++j)  //这个桶取了多少数 
                    (f[i][(j*i+w)%m]+=f[i-1][w]*pre[j])%=mod;
        }
        printf("%lld\n", f[m-1][0]);
    return 0;
}
