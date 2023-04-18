#include<bits/stdc++.h>
using namespace std;
bool usd[100005];
int sum[100005],num[100005],tot,index[100005];
struct edge
{
	int from,to,nxt;
}e[600005];
int Head[100005],cnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int pos[100005],du[100005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
		++du[x];
		++du[y];
	}
	for(int i=1;i<=n;++i)
	{
		if(!usd[du[i]])
		{
			++tot;
			usd[du[i]]=true;
			sum[tot]=du[i]; 
			index[du[i]]=tot;
			if(tot>3)return !printf("-1\n");
		}
		++num[du[i]];
	}
	for(int i=1;i<=n;++i)
		pos[i]=index[du[i]];
	if(tot==1)
	{
		int numt=0,numtt=0;
		for(int i=Head[1];i;i=e[i].nxt)pos[e[i].to]=2,++numt;
		for(int i=2;i<=n;++i)
		{
			int tt=0;
			if(pos[i]==1)
			{
				for(int j=Head[i];j;j=e[j].nxt)
				{
					if(pos[e[j].to]==1)return !printf("-1\n");
					++tt;
				}
				if(tt!=numt)return !printf("-1\n");
			}
		}
		int poss=0;
		for(int i=2;i<=n;++i)
		{
			if(pos[i]==2)
			{
				poss=i;break;
			}
		}
		for(int i=Head[poss];i;i=e[i].nxt)
		{
			if(pos[e[i].to]==2)
				pos[e[i].to]=3,++numtt;
		}
		for(int i=1;i<=n;++i)
		{
			int tt=0;
			if(pos[i]==2)
			{
				for(int j=Head[i];j;j=e[j].nxt)
				{
					if(pos[e[j].to]==2)return !printf("-1\n");
					if(pos[e[j].to]==3)++tt;
				}
				if(tt!=numt-numtt)return !printf("-1\n");
			}
		}		
	}
	else if(tot==3)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=Head[i];j;j=e[j].nxt)
			{
				if(pos[e[j].to]==pos[i])return !printf("-1\n");
			}		
		}
	}
	else
	{
		bool ky1,ky2;
		ky1=ky2=false;
		for(int i=1;i<=n;++i)
		{
			for(int j=Head[i];j;j=e[j].nxt)
			{
				if(pos[e[j].to]==pos[i])
				{
					if(pos[i]==1)ky1=true;
					else ky2=true;
				}
			}		
		}
		if(!(ky1^ky2))return !printf("-1\n");
		int sb;
		if(ky1)
			sb=1;
		else
			sb=2;
		int poss,numt=0;
		for(int i=1;i<=n;++i) 
		{
			if(pos[i]==sb)
			{
				poss=i;
				break;
			}
		}
		for(int i=Head[poss];i;i=e[i].nxt)
		{
			if(pos[e[i].to]==3-sb)
				pos[e[i].to]=3,++numt;
		}		
		for(int i=1;i<=n;++i)
		{
			int tt=0;
			if(pos[i]==sb)
			{
				for(int j=Head[i];j;j=e[j].nxt)
				{
					if(pos[e[j].to]==sb)return !printf("-1\n");
					if(pos[e[j].to]==3)++tt;
				}
				if(tt!=num[sum[sb]]-numt)return !printf("-1\n");
			}
		}				
	}
	for(int i=1;i<=n;++i)printf("%d ",pos[i]);
	return 0;
}
