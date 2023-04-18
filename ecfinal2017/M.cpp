#include<bits/stdc++.h>
using namespace std;
long long price[6];
int main()
{
	int t;
	scanf("%d",&t);
	for(int Case=1;Case<=t;++Case)
	{
		memset(price,0,sizeof(price));
		for(int i=1;i<=5;++i)
			scanf("%lld",&price[i]);
		long long tot=0;
		int n;
		scanf("%d",&n);
		while(n--)
		{
			int tt;
			scanf("%d",&tt);
			if(tt<=48)tot+=price[1];
			else if(tt<=56)tot+=price[2];
			else if(tt<=60)tot+=price[3];
			else if(tt<=62)tot+=price[4];
			else tot+=price[5];
		}
		tot*=10000;
		cout<<"Case #"<<Case<<": "<<tot<<endl;
	}
	
	return 0;
}
