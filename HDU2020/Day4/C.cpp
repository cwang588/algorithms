#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define rep(i,f_start,f_end) for (int i=f_start;i<=f_end;++i)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define MT(x,i) memset(x,i,sizeof(x) )
#define rev(i,start,end) for (int i=0;i<end;i++)
#define inf 0x3f3f3f3f3f3f3f3f
#define mp(x,y) make_pair(x,y)
#define lowbit(x) (x&-x)
#define MOD 1000000007
#define exp 1e-8
#define N 1000005 
#define fi first 
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int ,int> PII;
ll gcd (ll a,ll b) {return b?gcd (b,a%b):a; }
inline int read() {
    char ch=getchar(); int x=0, f=1;
    while(ch<'0'||ch>'9') {
        if(ch=='-') f = -1;
        ch=getchar();
    } 
    while('0'<=ch&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }   return x*f;
}
const int maxn=1e6+10;
ll dp[maxn];
ll dp2[maxn];
int t;
int n,m;

void solve () {
    int sum1=0,sum2=0;
    rep (i,1,n) {
        int x,y;
        cin>>x>>y;
        per (j,sum1,0) {
            if (dp[j]+y>dp[j+x]) dp[j+x]=dp[j]+y;
        }
        sum1+=x;
    }
    rep (i,1,m) {
        int x,y;
        cin>>x>>y;
        per (j,sum2,0) {
            if (dp2[j]+y>dp2[j+x]) dp2[j+x]=dp2[j]+y;
        }
        sum2+=x;
    }
    ll ans=0;
    int sum=min (sum1,sum2);
    rep (i,1,sum) {
        ans=max (ans,dp[i]+dp2[i]);
    }
    cout<<ans<<endl;
    rep (i,1,sum2) dp[i]=-1e15;
    rep (i,1,sum2) dp2[i]=-1e15; 
}

int main () {
   cin>>t;
   rep (i,1,maxn) {
       dp[i]=dp2[i]=-1e15;
   }
   while (t--) {
       cin>>n>>m;
       solve ();
   }
    return 0;
}

