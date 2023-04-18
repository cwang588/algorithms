#include<bits/stdc++.h>
using namespace std;

int main()
{
	for(int i=0;i<=9;++i)
	{
		int tot=0;
		for(int j=i+1;j<=9;++j)
		{
			for(int k=0;k<=9;++k)
				if(e[i+k]&&e[j+k])
					++tot;
			printf("%d ",tot);
		}
		printf("\n");
	}
	
	
	return 0;
}
