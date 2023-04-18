#include<bits/stdc++.h>
using namespace std;
inline int Rand()
{	
	return (rand()<<16)+rand();
}
map<int,bool>usd;
int a[100005];
int main()
{
	srand((unsigned)time(0));
	freopen("zz15192.in","w",stdout);
	int L=1000000000,n,m;
	n=100;
	m=100;
	printf("%d %d %d\n",L,n,m);
	for(int i=1;i<=n;++i)
	{
		int x=Rand()%L+1;
		while(usd[x])x=Rand()%L+1;
		a[i]=x;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)printf("%d\n",a[i]);
	return 0;
}
