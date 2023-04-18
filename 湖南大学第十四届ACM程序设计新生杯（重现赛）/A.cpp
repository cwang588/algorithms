#include<cstdio>
using namespace std;
int main()
{
	int n,l,t,ans;
	scanf("%d%d%d",&n,&l,&t);
	ans=n+1; 
	for(int i=1;i<=n;++i)
	{
		int p,d;
		scanf("%d%d",&p,&d);
		if(d==1)
		{
			if(l-p<=t)
				--ans;
		}
		else
		{
			if(p<=t)
				--ans;
		}	
	}
	printf("%d",ans);
	return 0;
}
 
