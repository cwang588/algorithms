#include<bits/stdc++.h>
using namespace std;
int ans1[100005],ans2[100005];
int main()
{
	int n,m,k,num1=0,num2=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==k)
			ans1[++num1]=y;
		if(y==k)
			ans2[++num2]=x;
	}
	for(int i=1;i<=num1;++i)
		printf("%d ",ans1[i]);
	printf("\n");
	for(int i=1;i<=num2;++i)
		printf("%d ",ans2[i]);
	printf("\n");
	return 0;
}
