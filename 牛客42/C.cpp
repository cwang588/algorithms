#include<cstdio>
using namespace std;
bool you[1000000009];
int a[1005][1005];
int main()
{
	int n,m;	
	scanf("%d%d",&n,&m);
	long long tot=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&a[i][j]);
			if(!you[a[i][j]])
			{
				tot=(tot+a[i][j])%1000000007;
				you[a[i][j]]=true;
			} 
		} 
	printf("%lld",(tot*tot)%1000000007);
	return 0;
}
