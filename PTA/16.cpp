#include<cstdio>
using namespace std;
int q[25]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char M[25]={'1','0','X','9','8','7','6','5','4','3','2'};
char id[105][25];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%s",&id[i]);
	bool you=false;
	for(int i=1;i<=n;++i)
	{
		bool hl=true;
		int tot=0;
		for(int j=0;j<17;++j)
		{
			if(id[i][j]>='0'&&id[i][j]<='9')
				tot+=q[j]*(id[i][j]-'0');
			else
			{
				hl=false;
				break;
			}
		}
		if(!hl||M[tot%11]!=id[i][17])
		{
			you=true;
			printf("%s\n",id[i]);
		}
	}
	if(!you)
		printf("All passed");
	return 0;
}
