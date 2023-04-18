#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	freopen("zz15239.in","w",stdout);
	int n,m;
	n=m=10000;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n+m-2;++i)printf("%d\n",rand()%100+1);
	return 0;
}
