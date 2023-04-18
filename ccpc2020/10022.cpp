#include<bits/stdc++.h>
  using namespace std;
  typedef long long int ll;
  const ll maxn=1E6+5;
 ll prime[maxn],size,id1[maxn],id2[maxn],m,n,back[maxn],sumF[maxn],sqr,g[maxn],mod,G;
  bool vis[maxn];
  void put(ll x,ll y)
 {
     if(x<=sqr)id1[x]=y;
     else id2[n/x]=y;
 }
 ll where(ll x)
 {
     if(x<=sqr)return id1[x];
     else return id2[n/x];
 }
 ll sum(ll n)
 {
     return (n*(n+1)%mod*G-1+mod)%mod;
 }
 void init(int n)
 {
     for(int i=2;i<=n;++i)
     {
         if(!vis[i])prime[++size]=i,sumF[size]=(sumF[size-1]+i)%mod;
         for(int j=1;j<=size&&i*prime[j]<=n;++j)
        {
             vis[i*prime[j]]=1;
             if(i%prime[j]==0)break;
         }
     }
 }
 void calc()
 {
     for(int j=1;j<=size;++j)
     {
         ll limit=prime[j]*prime[j];
         for(int i=1;back[i]>=limit;++i)
         {
             int k=where(back[i]/prime[j]);
             g[i]=(g[i]-prime[j]*(g[k]-sumF[j-1])%mod+mod)%mod;
         }
     }
 }
 void make()
 {
     for(ll i=1,j;i<=n;i=j+1)
     {
         back[++m]=n/i;
         j=n/back[m];
         put(n/i,m);
         g[m]=sum(n/i);
     }
 }
 ll Pow(ll x, ll y)
 {
     ll res = 1;
     while(y)
     {
         if(y & 1) res = (res * x) % mod;
         x = (x * x) % mod;
         y >>= 1;
     }
     return res;
 }
 int main()
 {
   //  ios::sync_with_stdio(false);
     int t; cin >> t;
     while(t--)
     {
         memset(prime, 0, sizeof(prime));
         memset(id1, 0, sizeof(id1));
         memset(id2, 0, sizeof(id2));
         memset(back, 0, sizeof(back));
         memset(sumF, 0, sizeof(sumF));
         memset(g, 0, sizeof(g));
         size = m = 0;
        cin>>n>>mod;
        n++;
        G = Pow(2, mod-2);
        sqr=sqrt(n)+100;
        init(sqr);
        make();
        calc();
    //  cout<<g[1]<<endl;
        ll ans = (g[1] + (((n * (n+1)) % mod) * G % mod)-5+mod)%mod;
        cout << ans << '\n';
     }
 //    system("pause");
 }
