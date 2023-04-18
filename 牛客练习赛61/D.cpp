#include<bits/stdc++.h>
using namespace std;
const long long INF=2147483647777777;
struct edge
{	
	int from,to,nxt;
	long long v;
}e1[400005],e2[400005];
int cnt1,cnt2,Head1[200005],Head2[200005];
void add1(int x,int y,long long z)
{
	++cnt1;
	e1[cnt1].from=x;
	e1[cnt1].to=y;
	e1[cnt1].nxt=Head1[x];
	e1[cnt1].v=z;
	Head1[x]=cnt1;
}
void add2(int x,int y,long long z)
{
	++cnt2;
	e2[cnt2].from=x;
	e2[cnt2].to=y;
	e2[cnt2].nxt=Head2[x];
	e2[cnt2].v=z;
	Head2[x]=cnt2;
}
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q1,q2;
long long dis1[100005],dis2[100005];
bool used1[100005],used2[100005];
int n;
void dijsktra1(int s)
{
	for(int i=1;i<=n;++i)
		dis1[i]=INF;
	dis1[s]=0;
	q1.push(make_pair(0,s));
	while(!q1.empty())
	{
		int now=q1.top().second;
		q1.pop();
		if(!used1[now])
		{
			used1[now]=true;
			for(int i=Head1[now];i;i=e1[i].nxt)
			{
				if(dis1[e1[i].to]>dis1[e1[i].from]+e1[i].v)
				{
					dis1[e1[i].to]=dis1[e1[i].from]+e1[i].v;
					q1.push(make_pair(dis1[e1[i].to],e1[i].to));
				}
			}
		}	
	}
}
void dijsktra2(int s)
{
	for(int i=1;i<=n;++i)
		dis2[i]=INF;
	dis2[s]=0;
	q2.push(make_pair(0,s));
	while(!q2.empty())
	{
		int now=q2.top().second;
		q2.pop();
		if(!used2[now])
		{
			used2[now]=true;
			for(int i=Head2[now];i;i=e2[i].nxt)
			{
				if(dis2[e2[i].to]>dis2[e2[i].from]+e2[i].v)
				{
					dis2[e2[i].to]=dis2[e2[i].from]+e2[i].v;
					q2.push(make_pair(dis2[e2[i].to],e2[i].to));
				}
			}
		}	
	}
}
struct ios {
    inline char gc(){
        static const int IN_LEN=1<<18|1;
        static char buf[IN_LEN],*s,*t;
        return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
    }

    template <typename _Tp> inline ios & operator >> (_Tp&x){
        static char ch,sgn; ch = gc(), sgn = 0;
        for(;!isdigit(ch);ch=gc()){if(ch==-1)return *this;sgn|=ch=='-';}
        for(x=0;isdigit(ch);ch=gc())x=x*10+(ch^'0');
        sgn&&(x=-x); return *this;
    }
} io;
int main()
{
	int m;	
//	io>>n>>m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		long long z;
		//io>>x>>y>>z;
		scanf("%d%d%lld",&x,&y,&z);
		add1(x,y,z);
		add2(y,x,z);
	}
	dijsktra1(1);
	dijsktra2(n);
	int q;
//	io>>q;
	scanf("%d",&q);
	while(q--)
	{
		int tmp;
		//io>>tmp;
		scanf("%d",&tmp);
		int x=e1[tmp].from,y=e1[tmp].to;
		if(dis1[y]+e1[tmp].v+dis2[x]<dis1[n])printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
