#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int x[55],y[55];
double dis[55];
void work(int case1)
{
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	for(int i=1;i<=54;++i)
		dis[i]=0.0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    int xx,yy;
    cin>>xx>>yy;
    for(int i=1;i<=n;i++)
    {
        dis[i]=(x[i]-xx)*(x[i]-xx)+(y[i]-yy)*(y[i]-yy);
    }
        double ankle[55];
        for(int i=1;i<=n;i++)
        {
            double t1,t2,t3;
            if(xx==x[i]&&yy==y[i])
            continue;
            if(i==1)
            {
                t1=sqrt((x[2]-x[1])*(x[2]-x[1])+(y[2]-y[1])*(y[2]-y[1]));
                t2=sqrt((x[n]-x[1])*(x[n]-x[1])+(y[n]-y[1])*(y[n]-y[1]));
                t3=sqrt((x[n]-x[2])*(x[n]-x[2])+(y[n]-y[2])*(y[n]-y[2]));
            }
            else if(i==n)
            {
                t1=sqrt((x[n]-x[1])*(x[n]-x[1])+(y[n]-y[1])*(y[n]-y[1]));
                t2=sqrt((x[n]-x[n-1])*(x[n]-x[n-1])+(y[n]-y[n-1])*(y[n]-y[n-1]));
                t3=sqrt((x[n-1]-x[1])*(x[n-1]-x[1])+(y[n-1]-y[1])*(y[n-1]-y[1]));
            }
            else
            {
                t1=sqrt((x[i+1]-x[i])*(x[i+1]-x[i])+(y[i+1]-y[i])*(y[i+1]-y[i]));
                t2=sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]));
                t3=sqrt((x[i-1]-x[i+1])*(x[i-1]-x[i+1])+(y[i-1]-y[i+1])*(y[i-1]-y[i+1]));
            }
            ankle[i]=acos((t1*t1+t2*t2-t3*t3)/(2*t1*t2));

        }
        double l=0;
        for(int i=1;i<=n;i++)
        {
            l+=sqrt(dis[i])*(acos(-1.0)-ankle[i]);
        }
        printf("Case #%d: %.3lf\n",case1,l);
}
int main()
{
    int t,case1=0;
    cin>>t;
    while(t--)
    {
    	++case1;
        work(case1); 
    } 
    return 0;
} 

