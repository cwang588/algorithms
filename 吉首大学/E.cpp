#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int tot=n,sum1=n,sum2=n;
		while(sum1>=3||sum2>=4)
		{
			int now=sum1/3+sum2/4;
			tot+=now;
			sum1=sum1%3+now;
			sum2=sum2%4+now;
		}
		printf("%d\n",tot);
	}
	return 0;
}
