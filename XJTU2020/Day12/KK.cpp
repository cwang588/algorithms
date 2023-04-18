#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
	a[0]=a[1]=1;
	for(int i=2;;++i)
	{
		a[i]=a[i-1]+a[i-2];
		if(a[i]>=1000000000)return !printf("%d\n",i);
	}
	return 0;
}
