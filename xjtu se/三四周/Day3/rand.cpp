#include<bits/stdc++.h>
using namespace std;
map<int,bool>m;
int main()
{
	freopen("wch1.in","w",stdout);
	int n=1000000;
	printf("%d\n",n);
	for(int i=1;i<=n;++i)
	{
		long long x=1000000001;
		while(x>1000000000||m[x])x=rand()*25536+rand();
		printf("%lld ",x);
		m[x]=true;
	}
	printf("\n");
	m.clear();
	for(int i=1;i<=n;++i)
	{
		long long x=1000000001;
		while(x>1000000000||m[x])x=rand()*25536+rand();
		printf("%lld ",x);
		m[x]=true;
	}
	printf("\n");
	return 0;
}
