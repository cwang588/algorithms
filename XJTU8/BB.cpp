#include<bits/stdc++.h>
using namespace std;
int ans[505];
int main()
{
	int t;
	scanf("%d",&t);
	for(int Case=1;Case<=t;++Case)
	{
		memset(ans,0,sizeof(ans));
		long long n,k;
		scanf("%lld%lld",&n,&k);	
		printf("Case #%d:\n",Case);
		long long d=(1<<k)-n-1;
		int i;
		d=(d+1)/2;
		for(i=1;i<64;++i)
		{
			ans[i]=d&1;
			d>>=1;
			if(!d)
				break;
		}
		long long now=1,tot=0;
		for(int j=1;j<k;++j)
		{
			if(ans[j])
			{
				tot-=now;
				cout<<now<<' '<<'-'<<endl;
			}
			else
			{
				tot+=now;
				cout<<now<<' '<<'+'<<endl;		
			}
			now*=2;
		}
		if(now+tot==n)
			cout<<now<<' ';
		else
			cout<<now+1<<' ';
		cout<<"+\n";
	}
	
	return 0;
}
