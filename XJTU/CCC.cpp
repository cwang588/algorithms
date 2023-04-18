#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("dabiao.txt","w",stdout);
	for(int i=1;i<=10000;++i)
	{
		int tot=0;
		for(int j=1;j*j<=i;++j)
			for(int k=1;k*k<=i;++k)
				if(j*j+k*k<=i&&j>k)
					tot+=i/(j*j+k*k);
		printf("%d %d\n",i,tot*2);
	}
	
	return 0;
} 
