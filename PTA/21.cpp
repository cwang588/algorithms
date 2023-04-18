#include<cstdio>
#include<cstring>
using namespace std;
char a[10005];
int num[5];
int db[5]={' ','G','P','L','T'};
int main()
{
	scanf("%s",&a);
	int l=strlen(a);
	for(int i=0;i<l;++i)
	{
		if(a[i]=='G'||a[i]=='g')
			++num[1];
		if(a[i]=='P'||a[i]=='p')
			++num[2];
		if(a[i]=='L'||a[i]=='l')
			++num[3];
		if(a[i]=='T'||a[i]=='t')
			++num[4];
	}
	while(num[1]||num[2]||num[3]||num[4])
	{
		if(num[1])
		{
			printf("G");
			--num[1];
		}
		if(num[2])
		{
			printf("P");
			--num[2];
		}
		if(num[3])
		{
			printf("L");
			--num[3];
		}
		if(num[4])
		{
			printf("T");
			--num[4];
		}
	}
	return 0;
}
