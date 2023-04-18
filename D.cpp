#include<bits/stdc++.h>
using namespace std;
int mi(int x,int y)
{
	int re=1;
	while(y--)re*=x;
	return re;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a=0,b=0;
	for(int i=1;i<=n;++i)
	{
		a+=i*mi(n-i,m);
		b+=mi(i-1,m);
	}
	printf("%d %d\n",a,b);
	return 0;
}
