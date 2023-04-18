#include<bits/stdc++.h>
#define MAXN 10000004
using namespace std;
int kmp[MAXN];
int la,lb; 
char a[MAXN],b[MAXN];
int main()
{
	std::ios::sync_with_stdio(false);
	long long aa,bb;
	while(cin>>aa>>bb)
	{
		memset(kmp,0,sizeof(kmp));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	    cin>>(a+1);
	    la=strlen(a+1);
	    for(int i=la;i>=1;--i)
	    {
	    	if(a[i]=='.')break;
	    	b[la-i+1]=a[i];
	    }
	    lb=strlen(b+1);
	    int j=0;
	    for(int i=2;i<=lb;i++)
	    {     
	    	while(j&&b[i]!=b[j+1])
	    		j=kmp[j];    
	        if(b[j+1]==b[i])
				j++;    
	        kmp[i]=j;
		}
		long long ans=-2147483647;
		for(int i=lb;i>=1;--i)
			ans=max(ans,aa*i-bb*(i-kmp[i]));
		printf("%lld\n",ans);
	}
    return 0;
}
