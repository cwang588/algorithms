#include<cstdio>
#include<algorithm>
using namespace std;
int aa[8]={0,1,1,1,2,2,2,3},bb[8]={0,0,1,1,1,1,2,2},cc[8]={0,0,0,1,1,2,2,2};
int main()
{
	int a,b,c,aaa=3,bbb=2,ccc=2;
	scanf("%d%d%d",&a,&b,&c);
	int ans=0;
	for(int i=1;i<=7;++i)
	{
		int tot=2147483647;
		int are=a+aa[i]-aaa,bre=b+bb[i]-bbb,cre=c+cc[i]-ccc;
		if(!are&&!bre&&!cre)
		{
			ans=max(ans,7-i);
			continue;
		}
		if(are<0||bre<0||cre<0)
		{
			bool clearlove=true;
			for(int j=i;j<7;++j)
			{
				if(a>=aa[j]&&b>=bb[j]&&c>=cc[j]&&(a<aa[j+1]||b<bb[j+1]||c<cc[j+1]))
				{
					ans=max(ans,j-i+1);
					clearlove=false;
					break;
				}
			}
			if(clearlove)
				ans=max(ans,8-i);
			continue;
		}
		tot=min(tot,are/aaa);
		tot=min(tot,bre/bbb);
		tot=min(tot,cre/ccc);
		are-=tot*3;
		bre-=tot*2;
		cre-=tot*2;
		tot*=7;
		tot+=8-i;
		bool clearlove7=true;
		for(int j=1;j<7;++j)
		{
			if(are>=aa[j]&&bre>=bb[j]&&cre>=cc[j]&&(are<aa[j+1]||bre<bb[j+1]||cre<cc[j+1]))
			{
				tot+=j;
				clearlove7=false;
				break;
			}
		}
		if(clearlove7)
			tot+=7;
		ans=max(ans,tot);
	}
	printf("%d",ans);
	return 0;
}
