#include<bits/stdc++.h>
using namespace std;
int cf[100000006];
int main()
{
	int tot,m;
	scanf("%d%d",&tot,&m);
	if(!m)
		return !printf("%d",tot);
	for(int i=1;i<=m;++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		cf[l]++;
		cf[r+1]--;
	}
	int ans=0,num=0;
	for(int i=0;i<=tot;++i)
	{
		num+=cf[i];
		if(!num)
			++ans;
	}
	printf("%d",ans);
	return 0;
}
