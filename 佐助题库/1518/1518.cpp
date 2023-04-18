#include<bits/stdc++.h>
using namespace std;
inline int Rand()
{	
	static long long  r=rand()+1;
	return (r*=233333LL)%=2147483647;
}
int main()
{
	freopen("zz1518.in","w",stdout);
	srand((unsigned)time(NULL));
	int n=1000;
	printf("%d\n",n);
	for(int i=1;i<=n;++i)cout<<Rand()%1000+1<<' '<<Rand()%1000000+1<<"\n";
	return 0;
}
