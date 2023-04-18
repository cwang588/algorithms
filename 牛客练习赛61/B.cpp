#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		if(n>m)swap(n,m);
		int ans=m;
		while(n!=m)
		{
			if(n*2<=m)n*=2,++ans;
			else
			{
				int tmp=2*n-m;
				n-=tmp;
				m-=tmp;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
