#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	freopen("in.txt","w",stdout);
	int n=1;
	printf("%d\n",n);
	for(int i=1;i<=n;++i)
	{
		int a=rand()%1000+1,b=rand()%1000+1,c=rand()%1000+1;
		printf("%d %d %d\n",a,b,c);
	}
	return 0;
}
