#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
//1 1 1 _ _ _  8
int n,cnt,not_zero,start;
long long mo=1000000007;
long long c[3005][3005],jie[100005],a[100005],ans,sumans,mulans;
inline long long min(long long a,long long b)
{
    return a<b?a:b;
}
void dfs(int now,int maxnum,int res)
{
    if(res==0)
    {
//		for(int i=1;i<=n;i++)
//			printf("%d ",a[i]);
//		printf("\n");
        cnt=start=1;
        mulans=c[n][a[1]];
        for(int i=2;i<=n;i++)
        {
            mulans*=c[n][a[i]];
           // mulans%=mo;
            if(a[i]!=a[i-1])
            {
                mulans*=c[n-start+1][cnt];
                //mulans%=mo;
                cnt=1;
                start=i;
                if(a[i]==0) 
                {
                    not_zero=i-1;
                    break;
                }
                continue;
            }
            cnt++;
        }
        if(a[n]!=0) not_zero=n;
        sumans+=mulans;
        //sumans%=mo;
        ans+=(sumans*not_zero);
        sumans=0;
        return;
    }
    if(now==maxnum)
    {
        a[now]=res;
        dfs(now+1,maxnum,0);
        a[now]=0;
        return;
    }
    for(int i=min(res,a[now-1]);i>=1;i--)
    {
        a[now]=i;
        dfs(now+1,maxnum,res-i);
        a[now]=0;
    }
}
int main()
{
//	freopen("test10.in","r",stdin); 
//	freopen("test10.out","w",stdout);
    for(n=2;n<=65;++n)
    {
    a[0]=n;
    for(int i=0;i<=n;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1]);
    }
    jie[0]=1;
    for(int i=1;i<=n*n;i++)
    {
        jie[i]=jie[i-1]*i;
        //jie[i]%=mo;
    }
//	for(int i=0;i<=n;i++)
//		printf("%d ",c[i]);
//	scanf("%d",&n); 
//	for(int j=1;j<=n;j++)
    {
//		memset(a,0,sizeof(a));
//		sumans=0;
//		dfs(1,j,0);
        dfs(1,n,n);
//		ans+=((sumans*c[j])%mo*j)%mo;
    }
    //ans%=mo;
//	printf("%lld %lld %lld\n",ans,jie[n],jie[n*n-n]);
    ans*=jie[n];
   // ans%=mo;
    ans*=jie[n*n-n];
   // ans%=mo; 
    printf("%lld\n",ans);
	}
    return 0; 
}  
