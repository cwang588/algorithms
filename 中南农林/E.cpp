#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		int w,k,tot=0;
		scanf("%d%d",&w,&k);
		int tep=k;
		while(tep)
		{
			a[++tot]=tep%w;
			tep/=w;
		}
		bool ky=true;
		for(int i=1;i<=tot;++i)
		{
			if(a[i]>1)
			{
				if(a[i]-w<-1)
				{
					ky=false;
					break;
				}
				else
					++a[i+1];
			}
		}
		if(ky)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
