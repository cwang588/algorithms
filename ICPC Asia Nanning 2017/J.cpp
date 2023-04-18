#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a=0,b=0,c=0;
		scanf("%d",&n);
		for(int i=1;i<=n*2;++i)
		{
			int t;
			scanf("%d",&t);
			t%=3;
			if(t==0)++a;
			else if(t==1)++b;
			else ++c;
		}
		if(n==1)
		{
			if(a==2||(b==1&&c==1))printf("NO\n");
			else printf("YES\n");
		}
		else
		{
			if(a>n)printf("NO\n");
			else if(a<=1)
			{
				if(b==0||c==0)printf("YES\n");
				else printf("NO\n");
			} 
			else
			{
				if(a%2)printf("YES\n");
				else
				{
					if(a==2)
					{
						if(b%2)printf("YES\n");
						else
						{
							if(b==0||c==0)printf("YES\n");
							else printf("NO\n");
						}
					}
					else printf("YES\n");
				}
			}
		}
	}
	return 0;
}
