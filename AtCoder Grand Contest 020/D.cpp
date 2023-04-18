#include<bits/stdc++.h>
using namespace std;
int len,a,b;
int calc(int x,int y)
{
	return (max(x,y)-1)/(min(x,y)+1)+1;
}
bool check(int x)
{
	int alen=(x/(len+1)*len+x%(len+1)),blen=x/(len+1);
	if(x%(len+1)==0)--blen;
	if(alen>a)return false;
	if(calc(a-alen,b-blen)>len)return false;
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		len=calc(a,b);
		int l=0,r=a+b;
		while(l<r-1)
		{
			int m=(l+r)>>1;
			if(check(m))l=m;
			else r=m;
		}
		int mid;
		if(check(r))mid=r;
		else mid=l;
		if(d<=mid)
		{
			for(int i=c;i<=d;++i)
			{
				if(i%(len+1))printf("A");
				else printf("B");
			}
			printf("\n");
		}
		else if(c>mid)
		{
			int tot=a+b;
			for(int i=c;i<=d;++i)
			{
				int nowt=tot-i+1;
				if(nowt%(len+1))printf("B");
				else printf("A");
			}
			printf("\n");
		}
		else
		{
			for(int i=c;i<=mid;++i)
			{
				if(i%(len+1))printf("A");
				else printf("B");
			}
			int tot=a+b;
			for(int i=mid+1;i<=d;++i)
			{
				int nowt=tot-i+1;
				if(nowt%(len+1))printf("B");
				else printf("A");
			}
			printf("\n");
		}
	}
	return 0;
}
