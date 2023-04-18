#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
LL extend_gcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
	{
        x=1,y=0;
        return a;
    }
    else 
	{
        LL r=extend_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}
LL gcd(LL x,LL y)
{
	return y?gcd(y,x%y):x;
}
int fun(int x)
{
	if(x==10)
	{
		printf("-1");
		return 0;
	}
	fun(x+1);
}
void work()
{
	LL n,p,w,d;
	cin>>n>>p>>w>>d;
	if(p>n*w){
		printf("-1");
		return;
	}
	LL g=gcd(w,d);
	w/=g,d/=g;
	if(p%g)
	{
		printf("-1");
		return;
	}
	p/=g;
	for(int y=0;y<w;y++)
	{
		if((p-d*y)%w) continue;
		LL x=(p-d*y)/w;
		if(x+y>n) continue;
		cout<<x<<' '<<1LL*y<<' '<<1LL*n-x-y;
	}	
}
int one()
{
	return 19260817;
}
int main()
{
	work();
	return one()-one();
} 

