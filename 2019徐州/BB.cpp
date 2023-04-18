#include<bits/stdc++.h>
using namespace std;
bool usd[105];
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=q;++i)
	{
		int x,y;
		cin>>x>>y;
		if(x==1)usd[y]=true;
		else
		{
			bool ky=false;
			for(int i=y;i<=n;++i) 
			{
				if(!usd[i])
				{
					ky=true;
					printf("%d\n",i);
					break;
				}
			}
			if(!ky)cout<<"-1"<<endl;
		}
	}
	return 0;
}
