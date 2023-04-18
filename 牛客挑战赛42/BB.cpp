#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x=114514;
	for(int i=2;;++i)	
	{
		while(x%i==0)
		{
			printf("%d ",i);
			x/=i;
		}
		if(x==1)return 0;
	}
	return 0;
}
