#include<bits/stdc++.h>
using namespace std;
int a[505][1005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i][1]);
	int ans=0;
	for(int i=1;i<=2000;++i)
	{
		int now=0,last=0;
		for(int j=1;j<=n+1;++j)
		{
			if(a[j][i]!=i)
			{
				if(last)
				{
					int num=j-last;
					if(num%2==0)
					{
						for(int k=1;k<=num/2;++k)
							a[++now][i+1]=i+1;
					}
					else
					{
						for(int k=1;k<=num/2;++k)
							a[++now][i+1]=i+1;
						++ans;
					}
					last=0;
				}
				else;
				a[++now][i+1]=a[j][i];
			}
			else
			{
				if(!last)last=j;
				else;
			}
		}
	}
	for(int i=1;i<=n;++i)
		if(a[i][2001])
			++ans;
	printf("%d\n",ans);
	return 0;
}
