#include<bits/stdc++.h>
using namespace std;
int p[400005],num[400005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(p,0,sizeof(p));
		memset(num,0,sizeof(num));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&p[i]);
		int a,b,c;
		a=b=c=0;
		bool ky=false;
		int now=1,totnum=n/2;
		for(int i=1;i<=n/2;++i)
		{
			++num[now];
			if(p[i]!=p[i+1])++now;
		}
		a=num[1];
		totnum-=num[now];
		int tot=0;
		for(int i=2;i<now;++i)
		{
			tot+=num[i];
			if(tot>a&&(totnum-a-tot)>a)
			{
				b=tot;
				c=totnum-a-tot;
				ky=true;
				break;
			}
		}
		if(ky)printf("%d %d %d\n",a,b,c);
		else printf("0 0 0\n");
	}
	return 0;
}
