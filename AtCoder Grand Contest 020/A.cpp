#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	int now=abs(a-b);
	if(now%2)printf("Borys\n");
	else printf("Alice\n");
	return 0;
}
