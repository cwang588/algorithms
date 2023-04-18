#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		if(n%m)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
