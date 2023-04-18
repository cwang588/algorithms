#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			b[a[i]]=i;
		}
		printf("1");
		int l=b[1],r=b[1];
		for(int i=2;i<=n;++i)
		{
			l=min(l,b[i]);
			r=max(r,b[i]);
			if(r-l+1==i)printf("1");
			else printf("0");
		}
		printf("\n");
	}
	
	
	return 0;
}
