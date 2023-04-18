#include<cstdio>
using namespace std;
int main()
{
//	freopen("sb10.in","r",stdin);
//	freopen("sb10.out","w",stdout);
    int n;
    long long sum1,sum2=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        long long t;
        scanf("%lld",&t);
        if(i==1)
            sum1=t;
        else
            sum1^=t;
        sum2=(sum2+t)%100000007;
    }
    printf("%lld",(sum1+sum2)%100000007);
    return 0;
}
