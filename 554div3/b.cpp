#include<bits/stdc++.h>
using namespace std;
int f[15];
char digit[200005];
int main()
{
	int n;
	scanf("%d",&n);
	cin>>digit+1;
	for(int i=1;i<=n;++i)
		scanf("%d",&f[i]);
	int now=1;
	for(int i=1;i<=n;++i)
	{
		if(f[digit[i]-'0']<=digit[i]-'0')
			++now;
		else
			break;
	}
	for(int i=now;i<=n;++i)
	{
		if(f[digit[i]-'0']<digit[i]-'0')
			break;
		digit[i]=(char)(f[digit[i]-'0']+'0');
	}
	for(int i=1;i<=n;++i)
		cout<<digit[i];
	return 0;
}
