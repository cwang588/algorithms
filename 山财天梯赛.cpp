#include<cstdio>
#include<bits/stdc++.h> 
using namespace std;
char a[105][100005];
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;++i)
		gets(a[i]);
	for(int i=1;i<=n;++i)
	{
		int l=strlen(a[i]);
		for(int j=0;j<l;++j)
		{
			if(!j)
			{
				printf("%c",tolower(a[i][j]));
				continue;
			}
			if(a[i][j]==' ')
				continue;
			if(a[i][j-1]==' ')
				printf("%c",toupper(a[i][j]));
			else
				printf("%c",tolower(a[i][j]));
		}
		printf("\n");
	}
	return 0;
}
