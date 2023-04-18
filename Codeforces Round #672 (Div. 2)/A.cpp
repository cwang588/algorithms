#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		bool ky=true;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=2;i<=n;++i)
		{
			if(a[i]>=a[i-1])
			{
				ky=false;
				break;
			}
		}
		if(!ky)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
