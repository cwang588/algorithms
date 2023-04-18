#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int i=2;i*i<=998244353;++i)
		if(998244353%i==0)
			return !printf("%d %d",i,998244353/i);
	printf("yes");
	return 0;
}
