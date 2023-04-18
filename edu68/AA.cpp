#include<bits/stdc++.h>
using namespace std;
int a[50];
bool usd[55];
int main()
{
	for(int i=1;i<=20;++i)
	{
		memset(usd,false,sizeof(usd));
		for(int j=1;j<=i;++j)
			a[j]=j;
		int re=i,now=1;
		while(now<=re)
		{
			int tot=0;
			for(int j=1;j<=i;++j)
				if(!usd[j])
				{
					++tot;
					if(tot==now)
					{
						usd[j]=true;
						break;
					}
				}
			--re;
			++now;
		}
		for(int j=1;j<=i;++j)
			if(!usd[j])
				cout<<j<<' ';
		cout<<endl;
	}
	
	return 0;
}
