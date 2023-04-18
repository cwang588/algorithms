#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL)); 
	int s,d,m;
	s=rand()%5;
	d=rand()%5+5;
	m=rand()%5+25;
	printf("%d %d %d\n",s,d,m);
	for(int i=1;i<=s;++i)
	{
		for(int j=1;j<=d;++j)
			printf("%d ",rand()%30+5);
		printf("\n");
	}
	return 0;
}
