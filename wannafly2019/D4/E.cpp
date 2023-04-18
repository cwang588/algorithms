#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
bool pd(int sum)
{
	int h=sum/60,m=sum%60;
	if(h%10==7||m%10==7)
		return true;
	return false;
}
int main()
{
	int x,a,b;
	scanf("%d%d%d",&x,&a,&b);
	int tot=a*60+b;
	for(int i=0;;++i)
	{
		int now=tot-x*i;
		while(now<0)
			now+=1440;
		if(pd(now))
			return !printf("%d",i);
	}
	return 0;
}
