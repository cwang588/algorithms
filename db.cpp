#include<bits/stdc++.h>
using namespace std;

int ans[1000000];
int main()
{
//	freopen("db.txt","w",stdout);
	for(int i=1;i<=1000000;++i)
	{
		for(int j=1;pow(10,j)<=i;++j)
		{
		//	++ans[i-(i%(int)pow(10,j))*(i/(int)pow(10,j))];
			if(i-(i%(int)pow(10,j))*(i/(int)pow(10,j))==100)
				printf("%d %d %d\n",i,i%(int)pow(10,j),i/(int)pow(10,j));
		}
	}
//	for(int i=1;i<=1000;++i)
//		printf("%d:%d\n",i,ans[i]);
	
	return 0;
}
