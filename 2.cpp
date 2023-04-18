#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(a<b)
		swap(a,b);
	return b?gcd(b,a%b):a;
}
int main()
{
	for(int t=1;t<=7;++t)
	{
		int ans=1;
		for(int i=1;i<=t;++i)
			for(int j=1;j<=t;++j)
			{
				ans=ans*i*j/gcd(i,j)/gcd(i,j);
			}
		printf("%d\n",ans);
	}
	return 0;
}
