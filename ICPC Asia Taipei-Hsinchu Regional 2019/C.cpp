#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	bool ky=true;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
			{
				if(i==j||j==k||i==k)continue;
				if(!a[k])ky=false;
				else
				{
					if((a[i]-a[j])%a[k])ky=false;
					else;
				}
			}
	if(ky)printf("yes\n");
	else printf("no\n");
	return 0;
} 
