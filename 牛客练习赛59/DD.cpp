#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main()
{
	a[0]=0;
	a[1]=1;
	a[2]=3;
	int num;
	for(int i=3;;++i)
	{
		++num;
		if(a[i-1]%2)a[i]=a[i-1]*2;
		else a[i]=a[i-1]*2+1;
		if(a[i]>1000000000000000000)
		{
			num=i;
			break;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long x;
		scanf("%lld",&x);
		for(int i=1;i<=num;++i)
		{
			if(x>a[i-1]&&x<=a[i])
			{
				if(i%2)printf("XiaoQiao\n");
				else printf("XiaoHuiHui\n");
				break;
			}
		}
	}
	return 0;
}
