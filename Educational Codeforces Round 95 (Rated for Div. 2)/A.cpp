#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;	
	scanf("%d",&t);
	while(t--)
	{
		long long x,y,k;
		scanf("%I64d%I64d%I64d",&x,&y,&k);
		printf("%I64d\n",(y*k+k-2)/(x-1)+1+k);
	}
	return 0;
}
