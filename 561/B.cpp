#include<bits/stdc++.h>
using namespace std;
char vowel[10]={'a','o','e','i','u'};
int main()
{
	int k;	
	scanf("%d",&k);
	if(k<25)
		return !printf("-1");
	int Max=0;
	for(int i=2;i*i<=k;++i)
		if(k%i==0)
			Max=i;
	if(Max<5)
		return !printf("-1");
	for(int i=1;i<=k/Max;++i)
	{
		for(int j=1;j<=Max;++j)
			cout<<vowel[(i+j-2)%5];
	}
	return 0;
}
