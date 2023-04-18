#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int tot;
	while(n--)
	{
		int t;
		scanf("%d",&t);
		t%=2;
		tot=(tot+t)%2;
	}
	tot%=2;
	if(tot)printf("ddd\n");
	else printf("bqp\n");
	return 0;
}
