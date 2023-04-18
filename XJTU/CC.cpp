#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("db.txt","w",stdout);
	int now=0;
	for(int i=1;i<=10000;++i)
	{
		int tot=0;
		for(int j=1;j<i;++j)
		{
			if(sqrt(i*i-j*j)*sqrt(i*i-j*j)==i*i-j*j)
				++tot;
		}
		now+=tot;
		printf("%d %d\n",i,now);
	}
	return 0;
}
