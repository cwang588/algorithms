#include<bits/stdc++.h>
using namespace std;
int f(int x)
{
	++x;
	while(x%10==0)
		x/=10;
	return x;
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n<=9)
		printf("9");
	else
	{
		int ans=9;
		while(n>9)
		{
			++ans;
			n=f(n);
		}
		printf("%d",ans);
	}
	return 0;
}
