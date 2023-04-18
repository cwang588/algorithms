#include<bits/stdc++.h>
using namespace std;
char s[1005][1005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cin>>s[i][j];
		if(s[1][1]=='1')printf("call\n");
		else printf("aoligei\n");
	}
	return 0;
}
