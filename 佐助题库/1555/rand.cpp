#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("10.in","w",stdout);
	srand((unsigned)time(0));
	int n=400;
	printf("%d\n",n);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%d ",rand()%255-127);
		printf("\n");
	}
	return 0;
}
