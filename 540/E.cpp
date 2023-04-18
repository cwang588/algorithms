#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	long long n,k;
	cin>>n>>k;	
	if(n>=k*(k-1))
		return !printf("NO");
	long long tot=0;
	printf("YES\n");
	for(int i=1;i<=k-2;++i)
	{
		if(i%2)
		{
			for(int j=i+1;j<k;++j)
				printf("%d %d\n%d %d\n",i,j,i+2,j-1);
			printf("%d %d\n",i,k);
		}
		else
		{
			for(int j=i+1;j<=k;++j)
				printf("%d %d\n%d %d\n",i+2,j-2,i,j);
			
		}
	}
	return 0;
}
