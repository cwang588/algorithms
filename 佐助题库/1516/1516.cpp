#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("in9.in","w",stdout);
	int m,n;
	m=n=100000;
	printf("%d %d\n",m,n);
	for(int i=1;i<=m;++i)printf("%d ",(rand()%10000+rand())%1000000+1);
	printf("\n");
	for(int i=1;i<=n;++i)printf("%d ",(rand()%10000+rand())%1000000+1);
	printf("\n");
	return 0;
}
