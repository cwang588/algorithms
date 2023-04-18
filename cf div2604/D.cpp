#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==0&&b==0)
	{
		if(abs(c-d)>1)return !printf("NO\n");
		printf("YES\n");
		if(c>d)printf("2 ");
		for(int i=1;i<=min(c,d);++i)printf("3 2 ");
		if(d>c)printf("3");
		return 0;
	}
	else if(a==0&&d==0)
	{
		if(abs(b-c)>1)return !printf("NO\n");
		printf("YES\n");
		if(b>c)printf("1 ");
		for(int i=1;i<=min(b,c);++i)printf("2 1 ");
		if(c>b)printf("2");
		return 0;
	}
	else if(c==0&&d==0)
	{
		if(abs(a-b)>1)return !printf("NO\n");
		printf("YES\n");
		if(a>b)printf("0 ");
		for(int i=1;i<=min(a,b);++i)printf("1 0 ");
		if(b>a)printf("1");
		return 0;
	}
	else
	{
		if(a>b||d>c)return !printf("NO\n");
		int x=b-a,y=c-d;
		if(abs(x-y)>1)return !printf("NO\n");
		printf("YES\n");
		if(x>y)printf("1 ");
		for(int i=1;i<=a;++i)printf("0 1 ");
		for(int i=1;i<=min(x,y);++i)printf("2 1 ");
		for(int i=1;i<=d;++i)printf("2 3 ");
		if(y>x)printf("2\n");
		return 0;
	}
	return 0;
}
