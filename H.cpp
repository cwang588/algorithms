#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char num[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		memset(num,' ',sizeof(num));
		cin>>num;
		int l=strlen(num);
		long long tot=l*(l+1)*(l+2)/6;
		for(int j=1;j<=strlen(num);++j)
		{
			if(num[j-1]=='0')
				tot+=l-j+1;
			if(num[j-1]==num[j]&&j<l)
				tot+=(l-j)*j;
		}
		printf("%lld\n",tot);
	}
	return 0;
}
