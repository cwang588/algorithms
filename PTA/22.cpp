#include<cstdio>
#include<cstring>
using namespace std;
char a[10005],b[10005];
int main()
{
	scanf("%s %s",&a,&b);
	bool aaa,bbb;
	aaa=bbb=true;
	if(getchar()!='\n')
		bbb=false;
	int aa,bb;

	aa=bb=0;
	for(int i=0;i<strlen(a);++i)
	{
		if(a[i]>='0'&&a[i]<='9')
			aa=aa*10+a[i]-'0';
		else
		{
			printf("? ");
			aaa=false;
			break;
		}
	}
	if(aaa&&(aa>1000||!aa))
	{
		aaa=false;
		printf("? ");
	}
	if(aaa)
		printf("%d ",aa);
	printf("+ "); 
	if(bbb)
	{
		for(int i=0;i<strlen(b);++i)
		{
			if(b[i]>='0'&&b[i]<='9')
				bb=bb*10+b[i]-'0';
			else
			{
				printf("? ");
				bbb=false;
				break;
			}
		}
		if((bb>1000||!bb)&&bbb)
		{
			bbb=false;
			printf("? ");
		}
		if(bbb)
			printf("%d ",bb);
	}
	else
		printf("? ");
	if(aaa&&bbb)
		printf("= %d",aa+bb);
	else
		printf("= ?");
	return 0;
}
