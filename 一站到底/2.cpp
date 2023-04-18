#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int now=0,tot=0;
		while(now<n-1)
		{
			tot+=(n-now+1)/2+now;
			now=(n-now+1)/2+now;
		}
		printf("%d\n",tot);
	}
	
	return 0;
} 
