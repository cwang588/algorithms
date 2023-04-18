#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct student
{
	int rank;
	char name[15];
}b[50],g[50];
int boy,girl;
char t[15];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int tt;
		scanf("%d %s",&tt,&t);
		if(tt==0)
		{
			b[++boy].rank=i;
			for(int j=0;j<strlen(t);++j)
				b[boy].name[j]=t[j]; 
		}
		else
		{
			g[++girl].rank=i;
			for(int j=0;j<strlen(t);++j)
				g[girl].name[j]=t[j]; 
		}		
	}
	for(int i=1;i<=boy;++i)
		printf("%s %s",b[]);
	return 0;
}
