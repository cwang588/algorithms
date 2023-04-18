#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int i=1;i<=100;++i)
		for(int j=1;j<=100;++j)
			if(i*j%(i+j)==0)
				printf("%d %d\n",i,j);
	return 0;
}
