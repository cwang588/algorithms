#include<bits/stdc++.h>
using namespace std;
char a[1005],b[1005];
int main()
{
	cin>>(a+1)>>(b+1);
	int n=strlen(a+1),m=strlen(b+1);
	int ans=2147483647;
	for(int i=1;i+m-1<=n;++i)
	{
		int tmp=0;
		for(int j=1;j<=m;++j)if(b[j]!=a[i+j-1])++tmp;
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}
