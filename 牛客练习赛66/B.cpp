#include<bits/stdc++.h>
using namespace std;
int a[1000050];
bool usd[10500000];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),usd[a[i]]=true;
	for(int i=1;i<=q;++i)
	{
		int k,x,y;
		scanf("%d%d%d",&k,&x,&y);
		if(x==y)
		{
			printf("0\n");
			continue;
		}
		if(a[x]==a[y])
		{
			if(usd[a[x]^k])printf("2\n");
			else printf("-1\n");
		}
		else
		{
			if((a[x]^a[y])==k)printf("1\n");
			else printf("-1\n");
		}
	}
	return 0;
}
