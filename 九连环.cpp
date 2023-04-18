#include<bits/stdc++.h>
using namespace std;
bool f[15],tep[15];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		tep[t]=f[t]=true;
	}
	int now1=9-n,now2=9-n,tot1=0,tot2=0,head1,head2;
	for(int i=1;i<=9;++i)
		if(f[i])
		{
			head1=head2=i;
			break;
		}
	while(now1)
	{
		++tot1;
		if(tot1%2)
		{
			if(f[1])
			{
				for(int i=2;i<=9;++i)
					if(f[i])
					{
						head1=i;
						break;
					}
				++now1; 
				f[1]=false;
			}
			else
			{
				--now1;
				f[1]=true;
				head1=1;
			}
		}
		else
		{
			if(f[head1+1])
			{
				++now1;
				f[head1+1]=false;
			}
			else
			{
				--now1;
				f[head1+1]=true;
			}
		}
		if(now1==9)
		{
			tot1+=341;
			break;
		}
	}
	for(int i=1;i<=9;++i)
		f[i]=tep[i];
	while(now2)
	{
		++tot2;
		if(tot2%2==0)
		{
			if(f[1])
			{
				for(int i=2;i<=9;++i)
					if(f[i])
					{
						head2=i;
						break;
					}
				f[1]=false;
				++now2; 
			}
			else
			{
				--now2;
				f[1]=true;
				head2=1;
			}
		}
		else
		{
			if(head2+1>9)
			{
				now2=999999;
				break;
			}
			if(f[head2+1])
			{
				++now2;
				f[head2+1]=false;
			}
			else
			{
				--now2;
				f[head2+1]=true;
			}
		}
		if(now2==9)
		{
			tot2+=341;
			break;
		}
	}
	printf("%d",min(tot1,tot2));
	return 0;
}
