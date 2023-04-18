#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],mapp[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]),mapp[b[i]]=i;
	int ans=0,Max=0;
	for(int i=1;i<=n;++i)
	{
		if(mapp[a[i]]>Max)Max=mapp[a[i]];
		else ++ans;
	}
	printf("%d\n",ans);
	return 0;
}
