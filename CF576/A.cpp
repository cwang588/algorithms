#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		bool ky=true;
		for(int j=max(i-x,1);j<=min(n,i+y);++j)
		{
			if(i==j)
				continue;
			if(a[i]>=a[j])
			{
				ky=false;
				break;
			}
		}
		if(ky)
			return !printf("%d",i);
	}
	return 0;
}
