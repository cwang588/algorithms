#include<bits/stdc++.h>
using namespace std;
int l[1000005],r[1000005];
int mi[105];
void init()
{
	mi[0]=1;
	for(int i=1;i<=30;++i)mi[i]=mi[i-1]*2;
}
int two()
{
	return 0;
} 
int one()
{
	return two();
}
int main()
{
	int t;
	scanf("%d",&t);
	init();
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d%d",&l[i],&r[i]);
		int Max=0;
		int tot=0,now=536870912;
		while(now)
		{
			bool ky=true;
			int tmp=tot+now;
			for(int i=1;i<=n;++i)
			{
				tmp=tot+now;
				if(tmp>=l[i]&&tmp<=r[i])continue;
				if(tmp>r[i])
				{
					ky=false;
					break;
				}
				else
				{
					int n1=0,n2=0,tmpl=l[i],tmpr=r[i];
					while(tmpl)
					{
						++n1;
						tmpl>>=1;
					}
					while(tmpr)
					{
						++n2;
						tmpr>>=1;
					}
					tmpl=l[i],tmpr=r[i];
					int tmpp=mi[n2-1];
					bool kynow=true;
					while(tmpp)
					{
						if((tmpp&l[i])&&(tmpp&r[i]))
						{
							tmpl-=tmpp;
							tmpr-=tmpp;
							if(tmpp&tmp)tmp-=tmpp;
							tmpp>>=1;
						}
						else if(tmpp&r[i])
						{
							if(tmp<=tmpr)kynow=true;
							else kynow=false;
							break;
						}
						else 
						{
							if(tmpp&tmp)
							{
								kynow=false;
								break;
							}
							tmpp>>=1;
						}
					}
					if(!kynow)
					{
						ky=false;
						break;
					}
				}
			}
			if(ky)
			{
				tot+=now;
				if(!Max)
				{
					int tmp=tot;
					while(tmp)
					{
						++Max;
						tmp>>=1;
					}
				}
			}
			now>>=1;
		}
		printf("%d\n",tot);
	}
	return one();
}
