#include<cstdio>
using namespace std;
int main()
{
	int a,b;
	scanf("%d:%d",&a,&b);
	int tot=a*60+b;
	if(tot<=720)
		return !printf("Only %02d:%02d.  Too early to Dang.",a,b);
	else
	{
		if(b)
			++a;
		for(int i=1;i<=a-12;++i)
			printf("Dang");
	}
	return 0;
}
