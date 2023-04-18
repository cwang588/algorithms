#include<bits/stdc++.h>
using namespace std;
int f[15][15],a[15];
int main()
{
	freopen("db.txt","w",stdout);
	for(int i=1;i<=10;++i)
	{
		for(int j=1;j<=i;++j)
			a[j]=j;
		f[i][i]=1;
		f[i][1]=1;
		while(next_permutation(a+1,a+i))
		{
			int now=0,ans=0;
			for(int j=1;j<=i;++j)
			{
				if(a[j]>now)
				{
					++ans;
					now=a[j];
				}
			}
			++f[i][ans];
		}
	}
	for(int i=1;i<=10;++i)
	{
		for(int j=1;j<=i;++j)
			printf("%d ",f[i][j]);
		printf("\n");
	}
	return 0;
}
