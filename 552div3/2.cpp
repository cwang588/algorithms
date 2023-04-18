#include<cstdio>
#include<algorithm>
using namespace std;
int a[105]; 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int num=0,x=0,y=0,z=0;
	for(int i=1;i<=n;++i)
		if(a[i]!=a[i-1])
		{
			++num;
			if(num==1)
				x=a[i];
			else if(num==2)
				y=a[i];
			else if(num==3)
				z=a[i];
			else;
		}
	if(num>3)
		return !printf("-1");
	else 
	{
		if(num==3)
		{
			if(x+z==y*2)
				return !printf("%d",z-y);
			else
				return !printf("-1");
		}
		else if(num==2)
		{
			if((y-x)%2)
				return !printf("%d",y-x);
			else
				return !printf("%d",(y-x)/2);
		}
		else
			return !printf("0");
	}
	return 0;
}
