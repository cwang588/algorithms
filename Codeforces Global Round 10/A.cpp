#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		bool ky=false;
		for(int i=2;i<=n;++i)
		{
			if(a[i]!=a[i-1])
			{
				ky=true;
				break;
			} 
		}
		printf("%d\n",ky?1:n);
	}
	return 0;
}
