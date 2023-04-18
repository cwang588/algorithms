#include<bits/stdc++.h>
using namespace std;
char ans[405][3];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=4;++j)
		{
			cin>>ans[(i-1)*4+j];
			if(ans[(i-1)*4+j][2]=='T')
				printf("%d",ans[(i-1)*4+j][0]-'A'+1);
		}
	}
	return 0;
}
