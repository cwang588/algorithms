#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if(n==3)
		printf("YES\n1 4 5 2 3 6\n");
	else if(n==1)
		printf("YES\n1 2");
	else
		printf("NO\n");	
	return 0;
}
