#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("data.txt","w",stdout);
	srand((unsigned)time(0));
	int x=420;
	for(int i=1;i<=150;++i)
	{
		printf("%d:%d\n",i,x+(rand()%30)*(rand()%3-2));
	}
	return 0;
}
