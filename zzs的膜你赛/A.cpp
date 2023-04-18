#include<bits/stdc++.h>
using namespace std;
int s[105];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)	
	{
		memset(s,0,sizeof(s));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			int tt;
			scanf("%d",&tt);
			++s[tt];
		}
		int num1=0,num2=0;
		for(int i=1;i<=100;++i)
		{
			if(s[i]==1)
				++num1;
			if(s[i]>2)
				++num2;
		}
		if(!num2)
		{
			if(num1%2)
				printf("No\n");
			else
				printf("Yes\n");
			continue;
		}
		printf("Yes\n");
	}
	
	return 0;
}
