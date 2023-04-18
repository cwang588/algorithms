#include<bits/stdc++.h>
#define MAXN 1000010
using namespace std;
int kmp[MAXN];
int la,lb,j; 
char a[MAXN],b[MAXN],tep[MAXN];
int n;
char c[10]={'A','B','C','D','E','F'};
int geta(int k)
{
	memset(a,' ',sizeof(a));
	int now=0,tot=0;
	for(int i=1;i<=n;++i)
	{
		int t=i;
		while(t)
		{
			if(t%k<10)
				tep[++now]=(char)('0'+t%k);
			else
				tep[++now]=c[t%k-10];
			t/=k;
		}
		while(now)
			a[++tot]=tep[now--];
	}
	return tot;
}
int main()
{
	scanf("%d",&n);
    cin>>(b+1);
    lb=strlen(b+1);
    for(int i=2;i<=lb;i++)
    {     
    	while(j&&b[i]!=b[j+1])
    		j=kmp[j];    
        if(b[j+1]==b[i])
			j++;    
        kmp[i]=j;
	}
    for(int k=2;k<=16;++k)
    {
    	j=0;
    	int M=geta(k);
	    for(int i=1;i<=M;++i)
	    {
	    	while(j>0&&b[j+1]!=a[i])
	        	j=kmp[j];
	        if(b[j+1]==a[i]) 
	            j++;
	        if(j==lb) 
				return !printf("yes");
	    }
	}
	printf("No");
    return 0;  
}
