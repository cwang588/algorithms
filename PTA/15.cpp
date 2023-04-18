#include<cstdio>
using namespace std;
int main()
{
	int n,l;
	char c;
	scanf("%d %c",&n,&c);
	if(n%2)
		l=(n+1)/2;
	else
		l=n/2;
	for(int i=1;i<=l;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%c",c);
		printf("\n"); 
	} 
	return 0;
}
