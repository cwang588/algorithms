#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			b[i]=b[i-1]+a[i];
			if(i>1)c[i]=max(c[i-1],a[i]+a[i-1]);
		}
		int tmp=min(y,x/2),ans=0;
		for(int i=0;i<=tmp;++i)
		{
			int now=x-i*2+1;
			ans=max(ans,c[now]*i+b[now]);
			ans=max(ans,b[x-2*i+2]+(a[x-2*i+1]+a[x-2*i+2])*i-a[x-2*i+2]);
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;++i)a[i]=b[i]=c[i]=0;
	}
	return 0;
}
