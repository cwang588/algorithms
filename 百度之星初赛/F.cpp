#include<bits/stdc++.h>
using namespace std;
int ans;
void work(int a,int b,int c)
{
	for(int i=0;i<=999/b+1&&i<=999/a+1;++i)
		for(int j=0;j<=(999-b*i)/c+1&&j<=999/a+1;++j)
		{
			int rea=1000-b*i-c*j,reb=1000-a*i,rec=1000-a*j;
			if((rea<=0&&reb<=0)||(rea<=0&&rec<=0)||(rec<=0&&reb<=0))ans=min(ans,i+j);
			else
			{
				if(rea<=0)ans=min(ans,i+j+min((reb-1)/c+1,(rec-1)/b+1));
				else if(reb<=0)ans=min(ans,i+j+min((rea-1)/c+1,(rec-1)/a+1));
				else if(rec<=0)ans=min(ans,i+j+min((reb-1)/a+1,(rea-1)/b+1));
				else
				{
					if((reb-1)/c+1==(rec-1)/b+1)ans=min(ans,i+j+(reb-1)/c+1);
					else;
				}
			}
		}	
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out1.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		ans=2147483647;
	//	int ansi,ansj;
		work(a,b,c);
		work(b,a,c);
		work(c,a,b);
		printf("%d\n",ans);
	}
	return 0;
}
