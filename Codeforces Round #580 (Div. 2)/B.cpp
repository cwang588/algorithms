#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,num1=0,num2=0,num3=0;
	scanf("%d",&n);
	long long tot=0;
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		if(t<0)
		{
			++num2;
			tot+=(long long)(-1-t);
		}
		else if(t==0)
		{
			++tot;
			++num3;
		}
		else
		{
			++num1;
			tot+=(long long)(t-1);
		}
	}
	if(num2%2&&!num3)
		tot+=2;
	printf("%lld\n",tot);
	return 0;
}
