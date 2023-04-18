#include<bits/stdc++.h>
using namespace std;
int usd[15];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char t;
		cin>>t;
		if(t=='L')
		{
			for(int i=1;i<=10;++i)
			{
				if(!usd[i])
				{
					usd[i]=1;
					break;					
				}
			}
		}
		else if(t=='R')
		{
			for(int i=10;i>=1;--i)
			{
				if(!usd[i])
				{
					usd[i]=1;
					break;
				}
			}
		}
		else
			usd[t-'0'+1]=0;
	}
	for(int i=1;i<=10;++i)
		printf("%d",usd[i]);
	printf("\n");
	return 0;
}
