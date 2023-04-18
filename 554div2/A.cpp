#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int num1=0,num2=0,num3=0,num4=0;
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		if(t%2)
			++num1;
		else
			++num2; 
	}
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(t%2)
			++num3;
		else
			++num4; 
	}	
	printf("%d",min(num1,num4)+min(num2,num3));
	return 0;
}
