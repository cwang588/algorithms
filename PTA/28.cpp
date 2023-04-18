#include<cstdio>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	if(a>b)
	{
		if(x&&y&&z)
			return !printf("The winner is b: %d + 3",b);
		int num=0;
		if(!x)
			++num;
		if(!y)
			++num;
		if(!z)
			++num;
		return !printf("The winner is a: %d + %d",a,num);
	}
	else
	{
		if(!x&&!y&&!z)
			return !printf("The winner is a: %d + 3",a);
		int num=0;
		if(x)
			++num;
		if(y)
			++num;
		if(z)
			++num;
		return !printf("The winner is b: %d + %d",b,num);
	}
	return 0;
}
