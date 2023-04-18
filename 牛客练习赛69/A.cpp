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
		int tot1=6*n%360,tot2=n/2%360;
		if(tot1>tot2)
		{
			if(n%2)
			{
				if(tot1-tot2<=180)printf("%d\n",tot1-tot2);
				else printf("%d\n",361-tot1+tot2);
			}
			else printf("%d\n",min(tot1-tot2,360-tot1+tot2));
		}
		else
		{
			if(n%2)
			{
				if(tot2-tot1>=180)printf("%d\n",360-tot2+tot1);
				else printf("%d\n",tot2+1-tot1);
			}
			else printf("%d\n",min(tot2-tot1,360-tot2+tot1));
		}
	}
	return 0;
}
