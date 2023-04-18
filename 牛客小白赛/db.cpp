#include<cstdio>
using namespace std;
int main()
{
	freopen("db.txt","w",stdout);
	printf("int db[]={0,");
	int tot=0;
	for(int i=1;i*i<=1e7;++i)
	{
		printf("%d,",i*i);
		++tot;
	}
	printf("};");
	printf("%d",tot); 
	return 0;
} 
