#include<cstdio>
using namespace std;
int a[100005];
int main()
{
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=t;++i)
	{
		int tep,pos;
		scanf("%d%d",&tep,&pos);
		if(tep==1)
		{
			for(int j=1;j<=m;++j)
				a[(pos-1)*m+j-1]=i;
		}
		else
		{
			for(int j=1;j<=n;++j)
				a[(j-1)*m+pos-1]=i;
		}
	}
	for(int i=0;i<n*m;++i)
	{
		printf("%d ",a[i]);
		if((i+1)%m==0)
			printf("\n");
	}
	return 0;
}
