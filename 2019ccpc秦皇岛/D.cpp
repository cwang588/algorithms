#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		while(n%2==0)n/=2;
		while(n%5==0)n/=5;
		if(n>1)printf("Yes\n");
		else printf("No\n"); 
	}
	return 0;
}
