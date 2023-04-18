#include<bits/stdc++.h>
using namespace std;
void print(int n)
{
	printf("1");
	for(int i=1;i<n;++i)printf("24");
	for(int i=1;i<n-1;++i)printf("53");
	printf("5");
	for(int i=1;i<n-1;++i)printf("64");
	printf("6");
	for(int i=1;i<n-1;++i)printf("15");
	printf("1");
	for(int i=1;i<n-1;++i)printf("26");
	printf("2");
	for(int i=1;i<n-2;++i)printf("31");
	printf("2");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n%2==0)
		{
			printf("245612");
			for(int i=4;i<=n;i+=2)print(i);
		} 
		else 
		{
			printf("126234543132621516");
			for(int i=5;i<=n;i+=2)print(i);
		}
		printf("\n");
	}
	return 0;
}
