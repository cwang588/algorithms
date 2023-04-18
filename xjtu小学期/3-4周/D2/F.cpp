#include<bits/stdc++.h>
using namespace std;
char a[5005],b[5005];
long long c[5005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&c[i]);
	cin>>(a+1);
	cin>>(b+1);
	int re=0,rre=0;
	for(int i=1;i<=n;++i)
		if(a[i]=='1')
		{
			++re;
			if(b[i]=='0')
				++rre;
		}
	bool st=false;
	while(re||rre)
	{
		long long Max=0,pos;
		for(int i=1;i<=n;++i)
			if(a[i]=='1')
			{
				if(a[i]=='0'&&!st)
				{
					int tot=0;
					for(int j=1;j<=n;++j)
					{
						
					}
				}
			}
	}
	return 0;
}
