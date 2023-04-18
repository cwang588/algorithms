#include<cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    if(n%4==1||n%4==0)
    {
        long long ans=1;
        for(int i=1;i<=n/4;++i)
            ans=(ans*(4*i-2))%998244353;
        printf("%lld",ans);
    }
    else
    {
        printf("0");
    }
    return 0;
}
