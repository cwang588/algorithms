#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime> 
using namespace std;

int rd()
{
	int x=rand();
	return (x<<16)+rand();
}
int main()
{
	//freopen("in.txt","w",stdout);
	srand((unsigned)time(NULL));
	int T=1;
	printf("%d\n",T);
	while(T--)
	{
		int n=rand()%10+10;
		int m=rand()%20+n;
		printf("%d %d\n",n,m);
		for(int i=1;i<=n;i++) printf("%d ",rd()%10001);
		printf("\n");
	}
}

