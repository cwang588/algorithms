#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("db.txt","w",stdout);
	for(int i=2;i<=20;++i)
		a[i]=i*i;
	for(int i=1;i<=400;++i)
	{
		int tot=0;
		for(int j=1;j*j<=i;++j)
		{
			if(i%j==0)
			{
				bool ky=true;
				for(int k=2;k<=15;++k)
					if(j%a[k]==0)
					{
						ky=false;
						break;
					}
				if(!ky)
					continue;
				for(int k=2;k<=15;++k)
					if((i/j)%a[k]==0)
					{
						ky=false;
						break;
					}
				if(!ky)
					continue;
				++tot;
				if(i/j!=j)
					++tot;					
			}
		}
		printf("%d %d\n",i,tot);
	}
	return 0;
}
