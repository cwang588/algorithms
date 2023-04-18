#include<cstdio>
using namespace std;
int main()
{
	int n,tot=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		if(t<60)
			tot+=400;
	}
	printf("%d",tot);
	return 0;
}
