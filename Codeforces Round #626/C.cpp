#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int num1=0,num2=0;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i];
		if(s[i]=='(')++num1;
		else ++num2;
	}
	if(num1!=num2)return !printf("-1\n");
	int now1=0,now2=0,last=0,ans=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='(')++now1;
		else ++now2;
		if(now1<now2)
		{
			if(!last)last=i;
			else;	
		}
		if(now1==now2)
		{
			if(last)
			{
				ans+=i-last+1;
				last=0;
			}
			now1=now2=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
