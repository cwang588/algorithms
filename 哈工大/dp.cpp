#include<bits/stdc++.h>
using namespace std;
int db[4000005];
void init()
{
	int pos=0;
	for(int i=1;i<=32768;++i)
	{
		int t=i,ws=0,now=1;
		for(int j=0;;++j)
		{
			if(i<now)
				break;		
			++ws;
			now*=10;
		}
		int k=0;
		while(t)
		{
			db[pos+ws-k]=t%10;
			++k;
			t/=10;
		}
		pos+=ws;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	init();
	for(int i=1;i<=t;++i)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",db[n]);
	}
	return 0;
}
