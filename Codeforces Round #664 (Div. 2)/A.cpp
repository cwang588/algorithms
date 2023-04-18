#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		bool zero=false;
		if(a==0||b==0||c==0)zero=true;
		a%=2;
		b%=2;
		c%=2;
		d%=2;
		if(a+b+c+d<=1)printf("Yes\n");
		else
		{
			if(a+b+c==3)printf("Yes\n");
			else if(a+b+c==2)
			{
				if(d==0||zero)printf("No\n");
				else printf("Yes\n");
			}
			else
			{
				if(d==0)printf("Yes\n");
				else printf("No\n");
			}
		}
	}
	return 0;
}
