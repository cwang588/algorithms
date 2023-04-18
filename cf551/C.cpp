#include<cstdio>
using namespace std;
char kh[300005];
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;++i)
		scanf("%c",&kh[i]);
	if(n%2)
		return !printf(":(\n");
	int num1=0,hlf=n/2,num2=0;
	for(int i=1;i<=n;++i)
	{
		if(kh[i]==')')
			++num2;
		if(num2*2>i)
			return !printf(":(\n");
	}
	for(int i=n;i>=1;--i)
	{
		if(kh[i]=='(')
			++num1;
		if(num1*2>(n-i+1))
			return !printf(":(\n");
	}
	int re=hlf-num1,tot=0;
	for(int i=1;i<=n;++i)
	{
		if(kh[i]=='?')
		{
			if(re)
			{
				kh[i]='(';
				--re;
			}
			else
				kh[i]=')';
		}
		if(kh[i]=='(')
			++tot;
		else
			--tot;
		if(i!=n&&tot==0)
			return !printf(":(\n");
	}
	for(int i=1;i<=n;++i)
		printf("%c",kh[i]);
	return 0;
}
