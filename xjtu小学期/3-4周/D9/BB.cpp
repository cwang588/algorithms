#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans,x1,y1;
LL x,m,y,n,l;
LL exgcd(LL a,LL b,LL &x1,LL &y1)
{
    if(!b)
    {
        x1=1;
        y1=0;
        return a;
    }
    ans=exgcd(b,a%b,x1,y1);
    LL t=x1;
    x1=y1;
    y1=t-a/b*y1;
    return ans;
}
int main()
{
	scanf("%lld%lld%lld%lld%lld",&x,&m,&y,&n,&l);
    LL b=n-m,a=x-y;
    if(b<0) b=-b,a=-a;
    exgcd(b,l,x1,y1);
    if(a%ans) printf("-1");
    else printf("%lld",((x1*(a/ans))%(l/ans)+(l/ans))%(l/ans));
    return 0;
}
