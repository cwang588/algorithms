#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m; 
		scanf("%d%d",&n,&m);
		if(n==m)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
