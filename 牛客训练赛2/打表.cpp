#include<bits/stdc++.h>
using namespace std;
bool prime[400000005];
int main()
{
	//freopen("db.txt","w",stdout);
	prime[2]=false;
	printf("int db[]={\n");
	int tot=0;
	for(int i=2;i<=300000000;++i)
		if(!prime[i])
		{
			++tot;
//			printf("%d,",i);
//			if(tot%10==0)
//			{
//				printf("\n");
//			}
			for(int j=2;i*j<=400000000;++j)
				prime[i*j]=true;
		}
	printf("%d",tot);
	return 0;
}
