#include<cstdio>
using namespace std;
bool prime[800000000];
int main()
{
	int num=0;
	prime[2]=false;
	for(int i=2;i<=800000000;++i)
	{
		if(!prime[i])
		{
			++num;
			for(int j=2;i*j<=800000000;++j)
				prime[i*j]=true;
		}
	}
	printf("%d",num);
	return 0;
}
