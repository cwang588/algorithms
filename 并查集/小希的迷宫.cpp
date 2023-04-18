#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int fa[100005];
int x[100005],y[100005];
bool usd[100005];
int getfa(int pos)
{
	if(fa[pos]!=pos)fa[pos]=getfa(fa[pos]);
	return fa[pos];
}
void Merge(int l,int r)
{
	int r1=getfa(l),r2=getfa(r);
	fa[r1]=r2;
}
int main()
{
	int cnt=0;
	while(1)
	{
		memset(usd,0,sizeof(usd));
		int Max=-1,num=1;
		scanf("%d%d",&x[num],&y[num]),usd[x[num]]=usd[y[num]]=true;
		Max=max(x[num],Max);
		Max=max(y[num],Max);
		if(x[1]==-1&&y[1]==-1)return 0;
		while(x[num]&&y[num])++num,scanf("%d%d",&x[num],&y[num]),usd[x[num]]=usd[y[num]]=true;
		for(int i=1;i<=Max;++i)fa[i]=i;
		bool ky=true;
		for(int i=1;i<=num-1;++i)
		{
			int r1=getfa(x[i]),r2=getfa(y[i]);
			if(r1!=r2)Merge(x[i],y[i]);
			else
			{
				ky=false;
				break;
			}
		}
		for(int i=1;i<=Max;++i)getfa(i);
		int last=0;
		for(int i=1;i<=Max;++i)
		{
			if(!usd[i])continue;
			if(last&&fa[i]!=fa[last])
			{
				ky=false;
				break;
			}
			last=i;
		}
		printf("Case %d is ",++cnt);
		if(!ky)printf("not ");
		printf("a tree.\n");
	}
	
	return 0;
}
