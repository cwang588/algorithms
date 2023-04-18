#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	int ans=1,now=2,tep=1;
	while(now<=n)
	{
		if(a[now+1]-a[now]!=1)
		{
			ans=max(ans,tep);
			tep=1;
		}
		else
			++tep;
		++now;
	}
	printf("%d",ans);
	return 0;
}
