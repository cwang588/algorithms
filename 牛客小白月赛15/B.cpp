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
		int tot=0;
		for(int i=1;i*i<=n;++i)
		{
			if(n%i==0)
			{
				++tot;
				if(i*i!=n)
					++tot; 
			}
		}
		printf("%d\n",tot);
	}
	return 0;
}
