#include <cstdio>
int n,a,tot;
int pow(int x,int p,int mod) 
{
    int ret=1;
    for(;p;p>>=1,x=1LL*x*x%mod) if(p&1) ret=1LL*ret*x%mod;
    return ret;
}
int solve(int p) 
{
    if(p==1) return 0;
    return pow(2,solve(phi[p])+phi[p],p);
}
int main()
{
    int p;
    scanf("%d",&p);
    printf("%d\n",solve(p));
    return 0;
}
