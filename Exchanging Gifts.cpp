#include<bits/stdc++.h>
using namespace std;
queue<int>q;
vector<int>v[1000005],e[1000005];
vector<int>V;
inline void add(int x,int y)
{
	e[x].push_back(y);
}
unordered_map<int,long long>fw,cs,rd,id,knum,EEnum;
inline int getid(int x){return lower_bound(V.begin(),V.end(),x)-V.begin()+1;}
inline int read() 
{
    char ch=getchar();
	int x=0,f=1;
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    } 
	while('0'<=ch&&ch<='9') 
	{
        x=x*10+ch-'0';
        ch=getchar();
    } 
	return x*f;
}
int main()
{
	int t;
	t=read();
	while(t--)
	{
		fw.clear();
		cs.clear();
		rd.clear();
		id.clear();
		knum.clear();
		EEnum.clear();
		V.clear();
		int n;
		long long tot=0,totk=0;
		n=read();
		int num=0;
		for(int i=1;i<=n;++i)
		{
			int tep;
			scanf("%d",&tep);
			if(tep==1)
			{
				int k;
				k=read();
				totk+=k;
				knum[i]=k;
				id[i]=++num;
				for(int j=1;j<=k;++j)
				{
					int tt;
					tt=read();
					V.push_back(tt);
					v[num].push_back(tt);
				}
			}
			else 
			{
				int x,y;
				x=read();
				y=read();
				add(i,x);
				add(i,y);
				EEnum[i]+=2;
				++rd[x];
				++rd[y];
			}
		}
		sort(V.begin(),V.end());
		V.erase(unique(V.begin(),V.end()),V.end());
		q.push(n);
		fw[n]=1;
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			for(int i=0;i<EEnum[now];++i)
			{
				int to=e[now][i];
				fw[to]+=fw[now];
				--rd[to];
				if(!rd[to])q.push(to);
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(id[i])
			{
				for(int j=0;j<knum[i];++j)
				{
					int now=getid(v[id[i]][j]);
					cs[now]+=fw[i];
					tot+=fw[i];
				}
				v[id[i]].clear();
			}
			e[i].clear();
		}
		bool ky=true;
		long long Max=0;
		for(int i=1;i<=totk;++i)
		{
			Max=max(Max,cs[i]);
			if(cs[i]*2>tot)
			{
				ky=false;
				break;
			}
		}	
		if(!ky)printf("%lld\n",(tot-Max)*2);
		else printf("%lld\n",tot);
	}
	return 0;
}
