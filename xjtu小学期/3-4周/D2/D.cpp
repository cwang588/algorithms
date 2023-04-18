#include<bits/stdc++.h>
using namespace std;
struct ddd
{
	double d,pi;
}dd[2500005];
bool cmp(ddd a,ddd b)
{
	return a.d<b.d;
}
int main() 
{
    double d1,c,d2,p,pmin=999999.0,l=0,pz=0;
    int n;
    cin>>d1>>c>>d2>>p>>n;
    dd[0].d=0;
    double d0=0;
    dd[0].pi=p;
    double x=c*d2; 
    for(int i=1;i<=n;i++)
        cin>>dd[i].d>>dd[i].pi;
    dd[n+1].d=d1;
    dd[n+1].pi=999999.0;
	sort(dd+1,dd+1+n,cmp);
    for(int i=1;i<=n+1;i++)
    {
        if(dd[i].d-dd[i-1].d>x)
		{
			cout<<"No Solution";
			return 0;
		}
    }
    int ii=0;
    while(d1-d0)
    {
        for(int i=ii+1;dd[i].d-d0<=x&&i<=n;i++)
        {
            if(dd[i].pi<pmin)
			{
				pmin=dd[i].pi;
				ii=i;
			}
        }
        if(pmin<=p)
		{
			pz+=((dd[ii].d-d0)/d2-l)*p;
			l=(dd[ii].d-d0)/d2;
		} 
        else if(d1-d0>x)  
        {
            pz+=(c-l)*p;
            l=c;
        }
        else
        {
            pz+=((d1-d0)/d2-l)*p;
			break; 
        }
        l=l-(dd[ii].d-d0)/d2; 
        d0=dd[ii].d; 
        p=pmin; 
        pmin=999999.0;
    }
    printf("%.2lf",pz);
    return 0; 
}
