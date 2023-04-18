#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if(n<=3)printf("NO\n");
	else if(n==4)printf("YES\n1*2*3*4\n");
	else if(n==5)printf("YES\n3*5+2*4+1\n");
	else if(n==6)printf("YES\n4*6*(2*3-5*1)\n");
	else
	{
		printf("YES\n");
		if(n%2==0)
		{
			for(int i=8;i<=n;i+=2)printf("(%d-%d)*",i,i-1);
			printf("4*6*(2*3-5*1)\n");
		}
		else
		{
			for(int i=9;i<=n;i+=2)printf("(%d-%d)*",i,i-1);
			printf("4*6*(3+5-7)*(2-1)\n");
		}
	}
	return 0;
}
