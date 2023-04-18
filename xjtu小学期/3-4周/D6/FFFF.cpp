#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for(int j=x;j<=y;++j)
			a[j]=i;
		int ans=1;
		for(int j=2;j<=n;++j)
			if(a[j]!=a[j-1])
				++ans;
		printf("%d\n",ans);
	}
	return 0;
}
