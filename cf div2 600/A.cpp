#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a)); 
		memset(b,0,sizeof(b)); 
		memset(c,0,sizeof(c)); 
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)scanf("%d",&b[i]);
		for(int i=1;i<=n;++i)c[i]=b[i]-a[i];
		bool ky=true,you=false;
		for(int i=1;i<=n;++i)
		{
			if(c[i]<0)
			{
				ky=false;
				break;
			}
			else if(!c[i])continue;
			else
			{
				if(you&&c[i-1]==0)
				{
					ky=false;
					break;
				}
				if(c[i-1]>0&&c[i]!=c[i-1])
				{
					ky=false;
					break;
				}
				you=true;
			}
		}
		if(ky)printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
} 
