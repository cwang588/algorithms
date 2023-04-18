#include<cstdio>
using namespace std;
double pr[15],now[15],dis[14];
int main()
{
	double d2,d1,c,ans=0.0;
	int n;
	scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&pr[0],&n);
	for(int i=1;i<=n;++i)
		scanf("%lf%lf",&dis[i],&pr[i]);
	ans+=pr[0]*c;
	pr[n+1]=9999.0;
	dis[n+1]=d1;
	now[0]=c;
	for(int i=1;i<=n+1;++i)
	{
		if(c*d2<dis[i]-dis[i-1])
			return !printf("No Solution");
		else
		{
			double cost=dis[i]-dis[i-1];
			while(cost>0)
			{
				double t=9999.0;
				int m;
				for(int j=0;j<i;++j)
					if(now[j]&&t>pr[j])
					{
						t=pr[j];
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
				if(now[j]&&pr[j]>pr[i])
				{
					now[i]+=now[j];
					ans+=now[j]*(pr[i]-pr[j]);
					now[j]=0;
				}
			double sum=0.0;
			for(int j=0;j<=n;++j)
				sum+=now[j];
			if(i<=n)
			{
				now[i]+=c-sum;
				ans+=(c-sum)*pr[i];
			}
		}
	}
	for(int i=0;i<=n;++i)
		if(now[i])
			ans-=now[i]*pr[i];
	printf("%.2lf",ans);
	return 0;
}
