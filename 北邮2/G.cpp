#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#define ll long long
using namespace std;
const int maxm=1e5+100;
struct node{
    ll sum;
    ll id;
}st[maxm<<2];
ll ans,n,t[maxm],cnt;
void build(ll o,ll l,ll r)
{
    if(l==r)
    {
        st[o].sum=t[l];
        st[o].id=l;
        return;
    }
    ll mid=(l+r)/2;
    build((o<<1),l,mid);
    build((o<<1)|1,mid+1,r);
    if(st[(o<<1)].sum<st[(o<<1)|1].sum) 
     st[o]=st[(o<<1)];
    else
     st[o]=st[(o<<1)|1];
}
ll ask(ll o,ll l,ll r,ll ql,ll qr)
{
    if(ql<=l&&r<=qr)
     return o;
    ll mid=(l+r)/2;
    ll o1,o2;
    if(qr<=mid) 
     return ask(o<<1,l,mid,ql,qr);
    if(ql>mid)
     return ask((o<<1)|1,mid+1,r,ql,qr);
    o1=ask((o<<1),l,mid,ql,qr),o2=ask((o<<1)|1,mid+1,r,ql,qr);
    if(st[o1].sum<st[o2].sum) return o1;
    else return o2;
}
void dfs(ll l,ll r,ll sum)
{
    if(l>r) return;
    ll o=ask(1,1,cnt,l,r);
    for(int i=1;i<=st[o].sum-sum;++i)
    	printf("%lld %lld\n",l,r);
    ans+=(st[o].sum-sum);
    dfs(l,st[o].id-1,st[o].sum);
    dfs(st[o].id+1,r,st[o].sum);
}
int main()
{
    scanf("%lld",&n);
    ll x;
    for(int i=1;i<=n;i++)
     {
         scanf("%lld",&x);
		 t[++cnt]=x;
		 if(t[cnt]>t[cnt-1])
		 	ans+=(t[cnt]-t[cnt-1]);
     }
     printf("%lld\n",ans);
    build(1,1,cnt);
    dfs(1,cnt,0);
    return 0;
} 
