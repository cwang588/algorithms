#include<cstdio>
using namespace std;
struct line
{
	int x,yy1,yy2;
}l[10005];
struct dian
{
	int x,y;
}up[10005],down[10005];
bool cmp(dian a,dian b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&l[i].x,&l[i].yy1,&l[i].yy2);
		up[i].x=down[i].x=l[i].x;
		up[i].y=l[i].yy1;
		down[i].y=l[i].yy2;
	}
	sort(up+1,up+1+n,cmp);
	sort(down+1,down+1+n,cmp);
	for(int i=n;i>=2)
	return 0;
}
