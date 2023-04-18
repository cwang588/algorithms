#include<cstdio>
using namespace std;
char mg[1005][1005];
int n,m,r,c,x,y;
bool usd1[1005][1005],usd2[1005][1005];
int main()
{
	scanf("%d%d",&n,&m,&r,&c,&x,&y);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>mg[i][j];
	
	return 0;
}
