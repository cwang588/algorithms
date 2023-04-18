#include<bits/stdc++.h>
using namespace std;
inline int read() 
{
    char ch=getchar();
	int x=0,f=1;
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    } 
	while('0'<=ch&&ch<='9') 
	{
        x=x*10+ch-'0';
        ch=getchar();
    } 
	return x*f;
}
int n;
struct point
{
	int x,y,w;
}p[100005];
double ansx,ansy,ans=1e18+7,t;
const double delta=0.993;
double rp()
{
	return (rand()*2-RAND_MAX)*t;
}
double nl(double x,double y)
{
	double tot=0.0;
	for(int i=1;i<=n;++i)
	{
		double xt=x-p[i].x;
		double yt=y-p[i].y;
		tot+=sqrt(xt*xt+yt*yt)*p[i].w;
	}
	return tot;
}
void wrng()
{
	double xx=ansx;
	double yy=ansx;
	t=1926;
	while(t>1e-14)
	{
		double xto=ansx+rp();
		double yto=ansy+rp();
		double new_ans=nl(xto,yto);
		if(new_ans<ans)
		{
			ansx=xx=xto;
			ansy=yy=yto;
			ans=new_ans;
		}
		else
		{
			double cj=new_ans-ans;
			if(exp(-cj/t)*RAND_MAX>rand())
			{
				xx=xto;
				yy=yto;
			}
		}
		t*=delta;
	}
}
void SA()
{
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
	wrng();
}
int main()
{
	srand((unsigned)time(0));
	n=read();
	for(int i=1;i<=n;++i)
	{
		p[i].x=read();
		p[i].y=read();
		p[i].w=read();
	}
	SA();
	printf("%.3lf %.3lf",ansx,ansy);
	return 0;
}
