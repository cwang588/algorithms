#include<bits/stdc++.h>
using namespace std;
long long s[10005];
char a[10005];
int main()
{
	long long ans=0,tot=0;
	cin>>a;
	for(int i=0;i<strlen(a);++i)
	{
		if(a[i]=='Q')
		{
			s[i+1]=s[i]+1;
			++tot;
		}
		else
			s[i+1]=s[i];
	}
	for(int i=0;i<strlen(a);++i)
	{
		if(a[i]=='A')
		{
			int num1=s[i+1],num2=tot-s[i+1];
			if(i!=0&&a[i-1]=='Q')
				--num1;
			if(a[i+1]=='Q')
				--num2;
			ans+=num1*num2;
		}
	}
	printf("%lld",ans);
	return 0;
}
