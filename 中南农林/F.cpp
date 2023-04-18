#include<bits/stdc++.h>
using namespace std;
char tt[1000005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(tt,' ',sizeof(tt));
		cin>>tt;
		int l=strlen(tt);
		long long tot=0,now=0;
		for(int i=0;i<l;++i)
		{
			if(tt[i]=='X')
				now=0;
			else
				tot+=++now;
		}
		cout<<tot<<endl;
	}
	return 0;
}
