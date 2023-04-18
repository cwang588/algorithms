#include<bits/stdc++.h>
using namespace std;
int Ceil(int x,int y)
{
	if(x%y)return x/y+1;
	return x/y;
}
int calc(int x,int y)
{
	if(x%y)return x/y;
	return x/y-1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(b>=c||d==0||c==0)printf("-1\n");
		else if(a<=d)printf("0\n");
		else
		{
			int tmp=Ceil(c-b,b);
			tmp*=d;
			printf("%d\n",calc(a,tmp));
		}
	}
	return 0;
}
