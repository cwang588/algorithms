#include<bits/stdc++.h>
using namespace std;
int a[100005],last[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(last,0,sizeof(last));
		int n,p;
		scanf("%d%d",&n,&p);
		for(int i=1;i<=n;++i)
		{
			int tmp;
			scanf("%d",&tmp);
			a[i]=(a[i-1]+tmp)%p;
		}
		int ans=0,start=0;
		for(int i=1;i<p;++i)last[i]=-1;
		for(int i=1;i<=n;++i)
		{
			if(last[a[i]]>=start)
			{
				++ans;
				start=i;
			}
			last[a[i]]=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
