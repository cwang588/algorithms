#include<bits/stdc++.h>
using namespace std;
void work(int x,int y)
{
	printf("%d %d:\n",x,y);
	int tmp=(max(x,y)-1)/(min(x,y)+1)+1,last=0,num=0;
	int tot=x+y;
	for(int i=1;i<=tot;++i)
	{
		if(x>0)
		{
			int now=(max(x-1,y)-1)/(min(x-1,y)+1)+1;
			if(now<=tmp&&((last==1&&num<tmp)||last!=1))
			{
				printf("A");
				--x;
				if(last==1)++num;
				else
				{
					last=1;
					num=1;
				}
			}
			else
			{
				printf("B");
				--y;
				if(last==2)++num;
				else
				{
					last=2;
					num=1;
				}
			}
		}
		else
		{
			printf("B");
			--y;
			if(last==2)++num;
			else
			{
				last=2;
				num=1;
			}
		}
	}
	printf("\n");
}
int main()
{
	for(int i=1;i<=10;++i)
		for(int j=1;j<=10;++j)
			work(i,j);
	return 0;
}
