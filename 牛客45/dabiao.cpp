#include<bits/stdc++.h>
using namespace std;
int a[15];
bool usd[15];
void judge(int x)
{
	int now=0;
	usd[0]=true;
	while(next_permutation(a,a+x))
	{
		memset(usd,false,sizeof(usd));
		now=0;
		usd[0]=true;
		bool ky=true;
		for(int i=0;i<x;++i)
		{
			now=(a[i]+now)%x;
			if(!usd[now])
				usd[now]=true;
			else
			{
				ky=false;
				break;
			}
			if(i==x-2)
			{
				ky=true;
				break;
			}
		}
		if(ky)
		{
			for(int i=0;i<x;++i)
				printf("%d ",a[i]);
			printf("\n");
			return;
		}
	}
	printf("\n");
}
int main()
{
	for(int i=1;i<=12;++i)
	{
		memset(a,0,sizeof(a));
		memset(usd,0,sizeof(usd));
		for(int j=0;j<i;++j)
			a[j]=j;
		judge(i);
	}
	
	return 0;
}
