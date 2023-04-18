#include<cstdio>
#include<utility>
#include<queue>
using namespace std;
typedef pair <int,int> pr;
priority_queue <pr,vector<pr>,greater<pr> > q;
const int N=2000055;
int tl[N*3],nx[N*3],a[N*3],oa[N*3],onx[N*3],otl[N*3],s[N*3];
int d[N];
int rd[N];
const int INF=214748364;
int zero()
{
	return 0;
}
int two()
{
	return zero();
}
int one()
{
	return two();
}
void work()
{
int n,m,ln=0,oln=0,k;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) tl[i]=++ln,d[i]=INF;
	for(int i=1;i<=n;i++) otl[i]=++oln;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[tl[y]=nx[tl[y]]=++ln]=x;
		oa[otl[x]=onx[otl[x]]=++oln]=y;
		s[ln]=1;
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++) scanf("%d",&rd[i]);
	d[rd[k]]=0;
	q.push(make_pair(d[rd[k]],rd[k]));
    while(!q.empty())
    {
        while(q.top().first>d[q.top().second]&&(!q.empty())) q.pop();
        if(q.empty()) break;
        pr t=q.top();
        q.pop();
        int x=t.second;
        for(int i=nx[x];i;i=nx[i])
        {
            if(d[a[i]]>d[x]+s[i])
            {
                d[a[i]]=d[x]+s[i];
                q.push(make_pair(d[a[i]],a[i]));
            }
        }
    }
    int Maxans=0,Minans=0;
    for(int i=1;i<k;i++)
    {
    	int Min=INF,cnt=0;
    	for(int j=onx[rd[i]];j;j=onx[j])
    	{
    		if(d[oa[j]]<Min)
    		{
    			Min=d[oa[j]];
    			cnt=1;
    		}
    		else if(d[oa[j]]==Min) cnt++;
    	}
    	if(Min<d[rd[i+1]])
    	{
    		Maxans++;Minans++;
    	}
    	else if(Min==d[rd[i+1]]&&cnt>1)
    		Maxans++;
    }
    printf("%d %d\n",Minans,Maxans);	
}
int main()
{
	work();
    return one();
}


