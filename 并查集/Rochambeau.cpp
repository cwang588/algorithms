#include<bits/stdc++.h>
using namespace std;
int fa[505],value[505];
int getfa(int x)
{
	if(fa[x]!=x)
	{
		int t=fa[x];
		fa[x]=getfa(fa[x]);
		value[x]^=value[t];
	}
	return fa[x];
}
void Merge(int x,int y,int z)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
	value[r1]=((value[y]-value[x]+z)%3+3)%3;
}
char s[2055];
int x[2005],y[2005];
int getnum(char t)
{
	if(t=='=')return 0;
	if(t=='>')return -1;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;++i)fa[i]=i,value[i]=0;
		int ans1=-1,ans2=-1;
		int ans=-1,ansnum;
		for(int i=1;i<=m;++i)cin>>x[i]>>s[i]>>y[i];
		bool ky=true;
		if(n==1)
		{
			printf("Player 0 can be determined to be the judge after 0 lines\n");
			continue;
		}
		for(int i=1;i<=m;++i)
		{
			int r1=getfa(x[i]),r2=getfa(y[i]);
			if(r1!=r2)
			{
				if(s[i]=='=')Merge(x[i],y[i],0);	
				else if(s[i]=='>')Merge(x[i],y[i],-1);	
				else Merge(x[i],y[i],1);	
			}
			else
			{
				getfa(x[i]),getfa(y[i]);
				int now=((value[x[i]]-value[y[i]])%3+3)%3;
				int noww=getnum(s[i]);
				if(noww!=now)
				{
					if(ans1==-1&&ans2==-1)
					{
						ans1=x[i];
						ans2=y[i];
					}	
					else if(ans1>=0&&ans2>=0)
					{
						if((x[i]==ans1&&y[i]==ans2)||(x[i]==ans2&&y[i]==ans1))continue;
						if(x[i]!=ans1&&x[i]!=ans2&&y[i]!=ans1&&y[i]!=ans2)
						{
							ky=false;
							break;
						}
						if(ans>=0)
						{
							ky=false;
							break;
						}
						if(x[i]==ans1&&y[i]!=ans2)ans=x[i];
						if(x[i]==ans2&&y[i]!=ans1)ans=x[i];
						if(x[i]!=ans1&&y[i]==ans2)ans=y[i];
						if(x[i]!=ans2&&y[i]==ans1)ans=y[i];
						ansnum=i;
					}
				}
			}
		}
		if(!ky)printf("Impossible\n");
		else
		{
			if(ans>=0)printf("Player %d can be determined to be the judge after %d lines\n",ans,ansnum);
			else printf("Can not determine\n");
		}
	}
	
	return 0;
}
