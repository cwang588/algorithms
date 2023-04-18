#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(k%2==0)
			printf("%d.00\n",k/2);
		else
			printf("%d.50\n",k/2);
	}
	return 0;
}
