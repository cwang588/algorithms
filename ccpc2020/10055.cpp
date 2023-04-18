#include<bits/stdc++.h>
using namespace std;
int sg[10005];
bool usd[1005];
int main()
{
	sg[1]=0;
	for(int i=1;i<=50;++i)
	{
		memset(usd,0,sizeof(usd));
		int now=0;
		for(int j=2;j<=i;++j)
		{
			if(i%j==0&&(i/j)%2)
				usd[sg[j]]=true;
		}
		for(int j=0;;++j)
		{
			if(!usd[j])
			{
				sg[i]=j;
				break;
			}
		}
		printf("%d:%d\n",i,sg[i]);
	}
	return 0;
} 
