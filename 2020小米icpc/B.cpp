#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
struct point{
	int x,y;
}p[615];
struct line{
	int X1,Y1,X2,Y2;
}L[305];
struct edge{
	int from,to,nxt;
	double value;
}e[500005];
int n,m,k;
int Head[605],cnt;
void add(int x,int y,double z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
inline int dcmp(double d)
{
    if(fabs(d) < eps) return 0;
    return d > 0 ? 1 : -1;
}
inline double det(double x1, double y1, double x2, double y2)
{
    return x1 * y2 - x2 * y1;
}
inline double cross(point a, point b, point c)
{
    return det(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y);
}
inline int segcross(point a, point b, point c, point d)
{
    return ((dcmp(cross(a, c, d)) ^ dcmp(cross(b, c, d))) == -2
       &&  (dcmp(cross(c, a, b)) ^ dcmp(cross(d, a, b))) == -2);
}
bool check(int l,int r){
	for(int i=1;i<=k;++i)if(segcross(p[l],p[r],point{L[i].X1,L[i].Y1},point{L[i].X2,L[i].Y2}))return false;
	return true;
}
double getdis(int l,int r){
	return sqrt((p[l].x-p[r].x)*(p[l].x-p[r].x)+(p[l].y-p[r].y)*(p[l].y-p[r].y));
}
const double INF=100000000000.0;
priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > > q;
double dis[100005];
bool usd[100005];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i){
		scanf("%d%d%d%d",&L[i].X1,&L[i].Y1,&L[i].X2,&L[i].Y2);
		p[i].x=L[i].X1;
		p[i].y=L[i].Y1;
		p[i+k].x=L[i].X2;
		p[i+k].y=L[i].Y2;
	}
	scanf("%d%d%d%d",&p[2*k+1].x,&p[2*k+1].y,&p[2*k+2].x,&p[2*k+2].y);
	for(int i=1;i<2*k+2;++i){ 
		for(int j=i+1;j<=2*k+2;++j){ 
			if(check(i,j)){
				double tmp=getdis(i,j);
				add(i,j,tmp);
				add(j,i,tmp);
			}
		} 
	}
	for(int i=1;i<=2*k+2;++i)
		dis[i]=INF;
	dis[2*k+1]=0;
	q.push(make_pair(0,2*k+1));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usd[now])
		{
			usd[now]=true;
			for(int i=Head[now];i;i=e[i].nxt)
			{
				if(dis[e[i].to]>dis[e[i].from]+e[i].value)
				{
					dis[e[i].to]=dis[e[i].from]+e[i].value;
					q.push(make_pair(dis[e[i].to],e[i].to));
				}
			}
		}	
	}
	printf("%.4f\n",dis[2*k+2]);	
	return 0;
}
