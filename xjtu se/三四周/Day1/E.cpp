#include<bits/stdc++.h>
using namespace std;
char a[100005],b[100005];
int main()
{
	cin>>(a+1)>>(b+1);
	int l1=strlen(a+1),l2=strlen(b+1);
	for(int i=1;i+l2-1<=l1;++i)
	{
		int num=0;
		for(int j=1;j<=l2;++j)
			if(a[i+j-1]!=b[j])
				++num;
		printf("%d\n",num);
	}
	return 0;
}
