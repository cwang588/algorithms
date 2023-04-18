#include<bits/stdc++.h>
using namespace std;
map<int,bool>usd1,usd2;
int main()
{
	freopen("in10.txt","w",stdout);
	srand((unsigned)time(0));
	int n=100000,m=100000;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;++i)
	{
		int x=rand()*10000+rand()+1;
		while(usd1[x])x=rand()+1;
		usd1[x]=true;
		printf("%d ",x);
	}
	printf("\n");
	for(int i=1;i<=m;++i)
	{
		int x=rand()*10000+rand()+1;
		while(usd2[x])x=rand()+1;
		usd2[x]=true;
		printf("%d ",x);
	}
	printf("\n");	
	return 0;
}
