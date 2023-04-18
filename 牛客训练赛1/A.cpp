#include<cstdio>
#include<iostream>
using namespace std;
int cz[105];
long long num[105];
int main()
{
	int n;
	long long x;
	scanf("%d",&n);
	cin>>x;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&cz[i]);
		cin>>num[i];
	}
	for(int i=n;i>0;--i)
	{
		switch(cz[i])
		{
			case(1):x-=num[i];break;
			case(2):x+=num[i];break;
			case(3):x/=num[i];break;
			case(4):x*=num[i];break;
		}
	}
	cout<<x;
	return 0;
}
