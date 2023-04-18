#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int _,n;
namespace linear_seq {
    const int N=10010;
    ll res[N],base[N],_c[N],_md[N];

    vector<int> Md;
    void mul(ll *a,ll *b,int k) {
        rep(i,0,k+k) _c[i]=0;
        rep(i,0,k) if (a[i]) rep(j,0,k) _c[i+j]=(_c[i+j]+a[i]*b[j])%mod;
        for (int i=k+k-1;i>=k;i--) if (_c[i])
            rep(j,0,SZ(Md)) _c[i-k+Md[j]]=(_c[i-k+Md[j]]-_c[i]*_md[Md[j]])%mod;
        rep(i,0,k) a[i]=_c[i];
    }
    int solve(ll n,VI a,VI b) { // a ?? b ?? b[n+1]=a[0]*b[n]+...
//        printf("%d\n",SZ(b));
        ll ans=0,pnt=0;
        int k=SZ(a);
        assert(SZ(a)==SZ(b));
        rep(i,0,k) _md[k-1-i]=-a[i];_md[k]=1;
        Md.clear();
        rep(i,0,k) if (_md[i]!=0) Md.push_back(i);
        rep(i,0,k) res[i]=base[i]=0;
        res[0]=1;
        while ((1ll<<pnt)<=n) pnt++;
        for (int p=pnt;p>=0;p--) {
            mul(res,res,k);
            if ((n>>p)&1) {
                for (int i=k-1;i>=0;i--) res[i+1]=res[i];res[0]=0;
                rep(j,0,SZ(Md)) res[Md[j]]=(res[Md[j]]-res[k]*_md[Md[j]])%mod;
            }
        }
        rep(i,0,k) ans=(ans+res[i]*b[i])%mod;
        if (ans<0) ans+=mod;
        return ans;
    }
    VI BM(VI s) {
        VI C(1,1),B(1,1);
        int L=0,m=1,b=1;
        rep(n,0,SZ(s)) {
            ll d=0;
            rep(i,0,L+1) d=(d+(ll)C[i]*s[n-i])%mod;
            if (d==0) ++m;
            else if (2*L<=n) {
                VI T=C;
                ll c=mod-d*powmod(b,mod-2)%mod;
                while (SZ(C)<SZ(B)+m) C.pb(0);
                rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
                L=n+1-L; B=T; b=d; m=1;
            } else {
                ll c=mod-d*powmod(b,mod-2)%mod;
                while (SZ(C)<SZ(B)+m) C.pb(0);
                rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
                ++m;
            }
        }
        return C;
    }
    int gao(VI a,ll n) {
        VI c=BM(a);
        c.erase(c.begin());
        rep(i,0,SZ(c)) c[i]=(mod-c[i])%mod;
        return solve(n,c,VI(a.begin(),a.begin()+SZ(c)));
    }
};

int main() {
    while (~scanf("%d",&n)) {
        vector<int>v;
        v.push_back(1);
        v.push_back(2);
 v.push_back(2);
 v.push_back(4);
 v.push_back(4);
 v.push_back(6);
 v.push_back(6);
 v.push_back(10);
 v.push_back(10);
 v.push_back(14);
 v.push_back(14);
 v.push_back(20);
 v.push_back(20);
 v.push_back(26);
 v.push_back(26);
 v.push_back(36);
 v.push_back(36);
 v.push_back(46);
 v.push_back(46);
 v.push_back(60);
 v.push_back(60);
 v.push_back(74);
 v.push_back(74);
 v.push_back(94);
 v.push_back(94);
 v.push_back(114);
 v.push_back(114);
 v.push_back(140);
 v.push_back(140);
 v.push_back(166);
 v.push_back(166);
 v.push_back(202);
 v.push_back(202);
 v.push_back(238);
 v.push_back(238);
 v.push_back(284);
 v.push_back(284);
 v.push_back(330);
 v.push_back(330);
 v.push_back(390);
 v.push_back(390);
 v.push_back(450);
 v.push_back(450);
 v.push_back(524);
 v.push_back(524);
 v.push_back(598);
 v.push_back(598);
 v.push_back(692);
 v.push_back(692);
 v.push_back(786);
 v.push_back(786);
 v.push_back(900);
 v.push_back(900);
 v.push_back(1014);
 v.push_back(1014);
 v.push_back(1154);
 v.push_back(1154);
 v.push_back(1294);
 v.push_back(1294);
 v.push_back(1460);
 v.push_back(1460);
 v.push_back(1626);
 v.push_back(1626);
 v.push_back(1828);
 v.push_back(1828);
 v.push_back(2030);
 v.push_back(2030);
 v.push_back(2268);
 v.push_back(2268);
 v.push_back(2506);
 v.push_back(2506);
 v.push_back(2790);
 v.push_back(2790);
 v.push_back(3074);
 v.push_back(3074);
 v.push_back(3404);
 v.push_back(3404);
 v.push_back(3734);
 v.push_back(3734);
 v.push_back(4124);
 v.push_back(4124);
 v.push_back(4514);
 v.push_back(4514);
 v.push_back(4964);
 v.push_back(4964);
 v.push_back(5414);
 v.push_back(5414);
 v.push_back(5938);
 v.push_back(5938);
 v.push_back(6462);
 v.push_back(6462);
 v.push_back(7060);
 v.push_back(7060);
 v.push_back(7658);
 v.push_back(7658);
 v.push_back(8350);
 v.push_back(8350);
 v.push_back(9042);
 v.push_back(9042);
 v.push_back(9828);
        //VI{1,2,4,7,13,24}
        printf("%d\n",linear_seq::gao(v,n-1));
    }
}

