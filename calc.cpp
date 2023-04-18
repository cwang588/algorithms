#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("db.txt","w",stdout);
	int n;
	for(int n=1;n<=5000;++n)
	{
		int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(i+j<=n)
					++ans;
		printf("%d\n",ans);
	}
	return 0;
}
