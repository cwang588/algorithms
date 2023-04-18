#include<bits/stdc++.h>
using namespace std;
int main()
{
	int now=0,tot=0;
	for(int i=1;i<=12;++i)
	{
		now+=300;
		int t;
		cin>>t;
		now-=t;
		if(now<0)
		{
			cout<<-i;
			return 0;
		}
		tot+=now/100*100;
		now-=now/100*100;
	}
	cout<<tot+tot/5+now;
	return 0;
}
