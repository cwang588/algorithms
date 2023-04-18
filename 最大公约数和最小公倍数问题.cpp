#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	if(y%x)return !printf("0\n");
	int tot=0,t=y/x;
	for(int i=1;i*i<=t;++i)
	{
		if(t%i==0&&gcd(i,t/i)==1)
		{
			++tot;
			if(i!=t/i)
				++tot;
		}
	}
	printf("%d\n",tot);
	return 0;
}
