#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int Case=1;Case<=t;++Case)
	{
		int n,ans;
		scanf("%d",&n);
		if(n==2)ans=1;
		else if(n==3)ans=6;
		else ans=n;
		printf("%d\n",ans);
	}
	
	return 0;
}
