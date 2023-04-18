#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int num1=0,num2=0;
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		if(t)
			++num1;
		else
			++num2;
	}
	if(!num2)
		return printf("-1");
	if(num1<9)
		return printf("0");
	for(int i=1;i<=num1/9*9;++i)
		printf("5");
	for(int i=1;i<=num2;++i)
		printf("0");
	return 0;
}
