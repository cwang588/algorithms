#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(0));
	freopen("zz15214.in","w",stdout);
	int n,s,a,b;
	n=5000;
	s=rand()%1000+1;
	a=rand()%50+1;
	b=rand()%200+1;
	printf("%d %d\n%d %d\n",n,s,a,b);
	for(int i=1;i<=n;++i)printf("%d %d\n",rand()%280+1,rand()%100+1);
	return 0;
}
