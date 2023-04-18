#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	for(int num=1;num<=100;++num)
	{
		int tot=0;
		for(int i=1;i<=num;++i)
			for(int j=1;j<=i;++j)
				if(gcd(i,j)==1)
					tot+=i-j;
		cout<<tot<<endl;
	}
	return 0;
}
