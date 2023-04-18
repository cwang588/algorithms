#include<bits/stdc++.h>
using namespace std;
int h[105];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(h,0,sizeof(h));
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;++i)	
			scanf("%d",&h[i]);
		bool ky=true;
		for(int i=1;i<n;++i)
		{
			int now=max(h[i+1]-k,0);
			if(h[i]<now)
			{
				if(h[i]+m<now)
				{
					ky=false;
					break;
				}
				m-=now-h[i]; 
			} 
			else
				m+=h[i]-now;
		}
		if(ky)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
