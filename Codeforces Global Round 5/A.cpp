#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main()
{
	int n,tot=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		b[i]=a[i]/2;
		tot+=b[i];
	}
	int now=1;
	while(tot)
	{
		if(a[now]%2)
		{
			if(tot>0&&a[now]<0)
			{
				--b[now];
				--tot;
			}
			else if(tot<0&&a[now]>0)
			{
				++b[now];
				++tot;
			}
		}
		++now;
	}
	for(int i=1;i<=n;++i)printf("%d\n",b[i]);
	return 0;
}	
