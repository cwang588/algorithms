#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int num[32];
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)	
	{
		memset(num,0,sizeof(num));
		int n;
		scanf("%d",&n);
		for(int j=1;j<=n;++j)
		{
			int x;
			scanf("%d",&x);
			++num[(int)(log(x)/log(2))];
		}
		int M=0;
		for(int j=0;j<=31;++j)
			if(num[j]>M)
				M=num[j];
		printf("%d\n",M);
	}
	
	
	
	
	return 0;
}
