#include<bits/stdc++.h>
#include<ctime>
using namespace std;
bool a[181];
int main()
{
	srand((unsigned)time(0));
	printf("请输入任意字符继续:");
	char c;
	a[0]=true;
	while(cin>>c)
	{
		loop:int t=rand()%180+1;
		if(!a[t])
		{
			printf("%d\n",t);
			a[t]=false;
		}
		else
			goto loop;
		printf("请输入任意字符继续:");
	}
	return 0;
}
