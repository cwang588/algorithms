#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l,r;
	scanf("%d%d",&l,&r);
	if(!l&&!r)
		return !printf("Not a moose");
	if(l==r)
		printf("Even ");
	else
		printf("Odd ");
	printf("%d",2*max(l,r));
	return 0;
}
