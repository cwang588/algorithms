#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int mi[45];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(k>n)
	{
		printf("NO");
		return 0;
	}
	int tot=0,m=0;
	while(n)
	{
		int t=n&(-n),w=0;
		n-=t;
		while(t!=1)
		{
			t/=2;
			++w;
		}
		mi[w]++;
		++tot;
		m=max(m,w);
	}
	if(tot>k)
	{
		printf("NO");
		return 0;
	}	
	for(int i=m;i;--i)
	{
		if(mi[i])
		{
			tot+=mi[i];
			if(tot<=k)
			{
				mi[i-1]+=mi[i]*2;
				mi[i]=0;
				if(tot==k)
					break;
			}
			else
			{
				tot-=mi[i];
				mi[i-1]+=2*(k-tot);
				mi[i]-=(k-tot);
				break;
			}
		}
	}
	printf("YES\n");
	for(int i=0;i<=m;++i)
		if(mi[i])
			for(int j=1;j<=mi[i];++j)
				printf("%d ",(int)pow(2,i));
	return 0;
}
