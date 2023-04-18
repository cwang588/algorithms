#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	long long n,m;
	cin>>n>>m;
	int q;
	scanf("%d",&q);
	long long t=gcd(n,m),t1=n/t,t2=m/t;
	while(q--)
	{
		int xx1,xx2;
		long long yy1,yy2;
		cin>>xx1>>yy1>>xx2>>yy2;
		long long base1,base2;
		--yy1,--yy2;
		if(xx1==1)base1=yy1/t1;
		else base1=yy1/t2;
		if(xx2==1)base2=yy2/t1;
		else base2=yy2/t2;
		if(base1==base2)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
