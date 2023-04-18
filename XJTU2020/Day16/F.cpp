#include<bits/stdc++.h>
using namespace std;
const long long inf=2147483647;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a,b,x,y;
		scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
		if(a<=b)
		{
			long long nowx=inf,nowy=inf;
			nowx=min(abs(x),abs(x-1));
			nowy=min(abs(y),abs(y+1));
			printf("%lld\n",a*max(nowx,nowy));
		}
		else
		{
			if(a>=2*b)a=2*b;
			long long nowx=inf,nowy=inf;
			nowx=min(abs(x),abs(x-1));
			nowy=min(abs(y),abs(y+1));
			printf("%lld\n",a*min(nowx,nowy)+b*abs(nowx-nowy));
		}
	}
	return 0;
}
