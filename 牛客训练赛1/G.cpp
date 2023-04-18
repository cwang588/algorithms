#include<cstdio>
#include<algorithm>
using namespace std;
int sum[100005],pos[100005];
bool usd[100005];
int Max,Min=999999;
int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&sum[i]);
		pos[sum[i]]=i;
	}
    int l=min(pos[x],pos[y]),r=max(pos[x],pos[y]);
    for(int i=l;i<=r;++i)
    {
		Max=max(Max,sum[i]);
    	Min=min(Min,sum[i]);
    	usd[sum[i]]=true;
   	}
    while(Max-Min!=r-l)
    {
    	for(int i=Min;i<=Max;++i)
    		if(!usd[i])
    		{
    			usd[i]=true;
    			Max=max(Max,sum[i]);
    			Min=min(Min,sum[i]);
    			l=min(l,pos[i]);
    			r=min(r,pos[i]);
			}
		for(int i=l;i<=r;++i)
    	{
			Max=max(Max,sum[i]);
    		Min=min(Min,sum[i]);
   		 	usd[sum[i]]=true;
   		}
    }
	printf("%d %d",l,r);
	return 0;
} 
