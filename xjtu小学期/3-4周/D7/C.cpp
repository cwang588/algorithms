#include<bits/stdc++.h>
using namespace std;
char b[200005];
int ans[200005],kmp[200005];
int main()
{
	cin>>(b+1);
	int lb=strlen(b+1),j=0;
	for(int i=2;i<=lb;i++)
    {     
    	while(j&&b[i]!=b[j+1])
    		j=kmp[j];    
        if(b[j+1]==b[i])
			j++;    
        kmp[i]=j;
	}
	int tot=0,now=lb;
	while(now)
	{
		ans[++tot]=kmp[now];
		now=kmp[now];
	}
	printf("%d\n",tot-1);
	for(int i=tot-1;i>=1;--i)
		printf("%d ",ans[i]);
	return 0;
}
