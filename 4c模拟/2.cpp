#include<cstdio>
using namespace std;
int main()
{
	int h,m;
	scanf("%d:%d",&h,&m);
	int tot=h*60+m;
	if(tot<=720)
		return !printf("Only %02d:%02d.  Too early to Dang.\n",h,m);
	if(m)
		++h;
	for(int i=1;i<=h-12;++i)
		printf("Dang");
	return 0;
}
