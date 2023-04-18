#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a=0,ans;
	freopen("dabiao.txt","w",stdout);
	for(int i=1;i<=1000;++i)
	{
		int t=0;
		for(int j=1;j<=i;++j)
			if(i%j==0)
				++t;
		if(a<t)
		{
			ans=i;
			a=t;
		}
		printf("%d %d\n",t,a);
	}
	
	return 0;
}
