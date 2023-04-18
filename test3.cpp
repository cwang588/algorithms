#include<bits/stdc++.h>
using namespace std;
int yh(int a,int b)
{
	int sum=0,count1=0;
	while(a||b)
	{
		if((a&1)&&(b&1))
		{
			count1++;
			a>>=1;
			b>>=1;
		}
		else if(((a&1)&&(b&1==0))||((a&1==0)&&(b&1)))
		{
			sum=pow(2,count1)+sum;
			count1++;
			a>>=1;
			b>>=1;
		}
		else if((a&1==0)&&(b&1==0))
		{
			count1++;
			a>>=1;
			b>>=1;
		}
//		else;
//		{
//			count1++;
//			a>>=1;
//			b>>=1;
//		}
	}
	return sum;
}
int main()
{
	printf("%d",yh(2,5));
	return 0;
}
