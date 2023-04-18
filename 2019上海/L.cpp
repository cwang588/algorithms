#include<bits/stdc++.h>
using namespace std;
int db[1000005][15];
void init()
{
	for(int b=2;b<=10;++b)
	{
		for(int i=1;i<=1000000;++i)
		{
			int ans=0;
			int tt=i;
			while(tt)
			{
				ans+=tt%b;
				tt/=b;
			}
			db[i][b]=db[i-1][b]+ans; 
		}
	}
}
int main()
{
	init();
	int t; 
	scanf("%d",&t);
	for(int Case=1;Case<=t;++Case)
	{
		int n,b;
		scanf("%d%d",&n,&b);
		printf("Case #%d: %d\n",Case,db[n][b]);
	}
	return 0;
}
