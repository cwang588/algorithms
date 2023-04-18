#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("10.in","w",stdout);
	srand((unsigned)time(0));
	int n=100000,k=1000000;
	printf("%d %d\n",n,k);
	for(int i=1;i<=n;++i)printf("%d\n",rand()*3000+rand()+1);
	return 0;
}
