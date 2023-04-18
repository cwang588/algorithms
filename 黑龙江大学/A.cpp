#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)	
	{
		int n;
		scanf("%d",&n);
		int tot=0,sum;
		for(int i=1;i<=200;++i)
		{
			tot+=i;
			if(tot>=n)
			{
				sum=i;
				break;
			}
		}
		int re=(sum-tot+n)%26;
		if(!re)
			re=26;
		printf("%c\n",(char)('a'+re-1));
	}
	return 0;
}
