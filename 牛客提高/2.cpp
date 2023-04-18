#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,seed,seedx,seedy;
int val[1000005],f[1000005][45],id[1000005][45];
int ans;
void generate_array()
{
    unsigned x=seed;
    for(int i=1;i<=n;++i)
    {
        x^=x<<13;
        x^=x>>17;
        x^=x<<5;
        val[i]=x%100;
    }
}
void generate_ask()
{
	int lastans=0,L,R;
    unsigned x=seedx,y=seedy;
    for(int i=1;i<=m;++i)
    {
        x^=x<<13;
        x^=x>>17;
        x^=x<<5;
        y^=y<<13;
        y^=y>>17;
        y^=y<<5;
        L=(x^lastans)%n+1,R=(y^lastans)%n+1;
        if(L>R)swap(L,R);
       	int k=log2(R-L+1);
       	if(f[L][k]>=f[R-(1<<k)+1][k])
       	{
       		if(i==1)
       			ans=id[L][k];
       		else
				ans^=id[L][k];	
			lastans=id[L][k];	   	 
       	}
		else
		{
			if(i==1)
       			ans=id[R-(1<<k)+1][k];
			else
				ans^=id[R-(1<<k)+1][k];		   	  
			lastans=id[R-(1<<k)+1][k];	    
		}
	}
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&seed,&seedx,&seedy);
	generate_array();
	for(int i=1;i<=n;++i)
	{
		id[i][0]=i;
		f[i][0]=val[i];
	}
	for(int j=1;j<=25;++j)
		for(int i=1;i+(1<<j)<=n+1;++i)
		{
			if(f[i][j-1]>=f[i+(1<<(j-1))][j-1])
			{
				f[i][j]=f[i][j-1];
				id[i][j]=id[i][j-1];
			}
			else
			{
				f[i][j]=f[i+(1<<(j-1))][j-1];
				id[i][j]=id[i+(1<<(j-1))][j-1];
			}
		}
	generate_ask();
	printf("%d",ans);
	return 0;
}
