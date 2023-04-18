#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL)); 
	int n=rand()%100+10;
	for(int i=1;i<=n;++i)
		printf("%d\n",rand()%5+1);
	return 0;
}
