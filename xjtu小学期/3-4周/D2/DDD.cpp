#include<bits/stdc++.h>
using namespace std;
double now[5000005];
struct ddd
{
	double pr,dis;
}dd[5000005];
bool cmp(ddd a,ddd b)
{
	return a.dis<b.dis;
}
int main()
{
    double d2,d1,c,ans=0.0;
    int n;
    scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&dd[0].pr,&n);
    for(int i=1;i<=n;++i)
        scanf("%lf%lf",&dd[i].dis,&dd[i].pr);
    ans+=dd[0].pr*c;
    dd[n+1].pr=9999999.0;
    dd[n+1].dis=d1;
    sort(dd+1,dd+1+n,cmp);
    now[0]=c;
    for(int i=1;i<=n+1;++i)
    {
        if(c*d2<dd[i].dis-dd[i-1].dis)
            return !printf("No Solution");
        else
        {
            double cost=dd[i].dis-dd[i-1].dis;
            while(cost>0)
            {
                double t=9999999.0;
                int m;
                for(int j=0;j<i;++j)
                    if(now[j]&&t>dd[j].pr)
                    {
                        t=dd[j].pr;
                        m=j;
                    }
                if(cost<now[m]*d2)
                {
                    now[m]-=cost/d2;                    
                    cost=0;
                }
                else
                {
                    cost-=d2*now[m];
                    now[m]=0;
                }           
            }
            for(int j=0;j<i;++j)
                if(now[j]&&dd[j].pr>dd[i].pr)
                {
                    now[i]+=now[j];
                    ans+=now[j]*(dd[i].pr-dd[j].pr);
                    now[j]=0;
                }
            double sum=0.0;
            for(int j=0;j<=n;++j)
                sum+=now[j];
            if(i<=n)
            {
                now[i]+=c-sum;
                ans+=(c-sum)*dd[i].pr;
            }
        }
    }
    for(int i=0;i<=n;++i)
        if(now[i])
            ans-=now[i]*dd[i].pr;
    printf("%.2lf",ans);
    return 0;
}
