#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int p,m;
		scanf("%d%d",&p,&m);
		if(p==1)
			printf("Bob\n");
		else
		{
			if((p-1)%(m+1)!=0||(p-1<=m))
				printf("Alice\n");
			else
				printf("Bob\n");
		}
	}
	return 0;
}
