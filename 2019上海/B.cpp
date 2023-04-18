#include<bits/stdc++.h>
using namespace std;
short cf[1000005];
int main()
{
	int t;
	scanf("%d",&t);
	for(int Case=1;Case<=t;++Case)
	{
		memset(cf,0,sizeof(cf));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			++cf[l];
			--cf[r+1]; 
		} 
		int tot=0,ans=0;
		for(int i=1;i<=n;++i)
		{
			tot+=(int)cf[i];
			if(tot%2)++ans;
		}
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}
