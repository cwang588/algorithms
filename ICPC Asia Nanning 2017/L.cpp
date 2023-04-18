#include<bits/stdc++.h>
using namespace std;
struct number
{
	int a[1005];
	int tot;
	number()
	{
		tot=0;
	}
}num[1005];
void add2(int x)
{
	num[x].a[1]+=2;
	for(int i=1;i<=num[x].tot;++i)
	{
		if(num[x].a[i]>=10)
		{
			++num[x].a[i+1];
			num[x].a[i]-=10;
		}
	}
	if(num[x].a[num[x].tot+1])++num[x].tot;
}
void multi6(int x)
{
	for(int i=1;i<=num[x].tot;++i)num[x].a[i]*=6;
	for(int i=1;i<=num[x].tot;++i)
	{
		if(num[x].a[i]>=10)
		{
			num[x].a[i+1]+=num[x].a[i]/10;
			num[x].a[i]%=10;
		}
	}
	if(num[x].a[num[x].tot+1])++num[x].tot;
}
void Minus(int x,int y)
{
	for(int i=num[y].tot;i>=1;--i)
		num[x].a[i]-=num[y].a[i];
	for(int i=1;i<num[x].tot;++i)
	{
		if(num[x].a[i]<0)
		{
			--num[x].a[i+1];
			num[x].a[i]+=10;
		}
	}
	if(!num[x].a[num[x].tot])--num[x].tot;
}
void init()
{
	num[1].a[1]=3;
	num[1].tot=1;
	num[2].a[2]=2;
	num[2].tot=2;
	for(int i=3;i<=1000;++i)
	{
		num[i]=num[i-1];
		multi6(i);
		add2(i);
		Minus(i,i-2);
	}
}
char tmp[100005];
void print(int x)
{
	for(int i=num[x].tot;i>=1;--i)printf("%d",num[x].a[i]);
	printf("\n");
}
int main()
{
	ios::sync_with_stdio(false);
	init();
	int n,sbb=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>(tmp+1);
		int tot=strlen(tmp+1);
		for(int j=1;2*j<=tot;++j)swap(tmp[j],tmp[tot-j+1]);
		for(int j=1;j<=300;++j)
		{
			if(tot<num[j].tot)
			{
				print(j);
				break;
			}
			else if(tot>num[j].tot)continue;
			else
			{
				bool ky=true;
				for(int k=tot;k>=1;--k)
				{
					int now=(int)(tmp[k]-'0');
					if(now<num[j].a[k])
					{
						ky=true;
						break;
					}
					else if(now>num[j].a[k])
					{
						ky=false;
						break;
					}
					else continue;
				}
				if(ky)
				{
					print(j);
					goto sb;
				}
				else continue;
			}
		}
		sb:++sbb;
	}
	return 0;
}
