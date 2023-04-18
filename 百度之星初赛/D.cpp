#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int l=0,r=0;
		for(int i=1;i<=n;++i)
		{
			int x,y;
			cin>>x>>y;
			if(x==1)r=max(r,y);
			else l=max(l,y);
		}
		if(l==0)
		{
			printf("%d\n",r+1);
			continue;
		}
		if(r==0)
		{
			printf("%d\n",l+2);
			continue;
		}
		if(r==l+1)printf("%d\n",l+3);
		else if(r>l+1)printf("%d\n",r+1);
		else printf("%d\n",l+2);
	}
	return 0;
}
