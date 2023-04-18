#include<cstdio>
using namespace std;
int main()
{
	int b,k;
	bool jo=false;
	scanf("%d%d",&b,&k);
	for(int i=k-1;i>=1;--i)
	{
		int t;
		scanf("%d",&t);
		if(b%2)
		{
			if(t%2)
				jo=!jo;
		}
	}
	int tt;
	scanf("%d",&tt);
	if(tt%2)
		jo=!jo;
	if(jo)
		printf("odd");
	else
		printf("even");
	return 0;
} 
