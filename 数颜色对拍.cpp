#include<bits/stdc++.h>
using namespace std;
int a[105]; 
bool usd[105];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)
	{
		char t;
		int l,r;
		cin>>t>>l>>r;
		if(t=='Q')
		{
			int ans=0;
			memset(usd,0,sizeof(usd));
			for(int i=l;i<=r;++i)
			{
				if(!usd[a[i]])
				{
					++ans;
					usd[a[i]]=true;
				}
			}
			printf("%d\n",ans);
		}
		else a[l]=r;
	}
	return 0;
}
