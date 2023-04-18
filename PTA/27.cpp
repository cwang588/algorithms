#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct student
{
	char a[15];
	int num;
}s[10005];
int main()
{
	int n,tot=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s %d",&s[i].a,&s[i].num);
		tot+=s[i].num;
	}
	int Min=9999999,t=0;
	for(int i=1;i<=n;++i)
	{
		if(Min>abs(tot-s[i].num*n*2))
		{
			Min=abs(tot-s[i].num*n*2);
			t=i;
		} 
	}
	printf("%d %s",(int)((double)tot/(double)n/2.0),s[t].a);
	return 0;
}
