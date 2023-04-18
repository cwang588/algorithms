#include<bits/stdc++.h>
using namespace std;
char a[305],b[305];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	cin>>(a+1)>>(b+1);
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int l=i,r=j,now=0,tot=0;
			while(l<=n&&r<=n&&now<=k)
			{
				if(a[l]!=b[r])++now;
				++l,++r,++tot;
				if(now<=k)ans=max(ans,tot);
			} 
		}
	printf("%d\n",ans);
	return 0;
}
