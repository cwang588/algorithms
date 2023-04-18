#include<bits/stdc++.h>
using namespace std;
struct qq
{
	int id,num;
}c[5005],r[5005];
bool cmp1(qq a,qq b)
{
	if(a.num!=b.num)
		return a.num>b.num;
	return a.id<b.id; 
}
bool cmp2(qq a,qq b)
{
	return a.id<b.id;
}
int main()
{
	int n,m,x,y,q;
	scanf("%d%d%d%d%d",&n,&m,&x,&y,&q);
	for(int i=1;i<=n;++i)
		r[i].id=i;
	for(int i=1;i<=m;++i)
		c[i].id=i;	
	for(int i=1;i<=q;++i)
	{
		int xx1,xx2,yy1,yy2;
		scanf("%d%d%d%d",&xx1,&yy1,&xx2,&yy2);
		if(xx1==xx2)
			++c[min(yy1,yy2)].num;
		else
			++r[min(xx1,xx2)].num;
	}
	sort(c+1,c+1+m,cmp1);
	sort(r+1,r+1+n,cmp1);
	sort(c+1,c+1+y,cmp2);
	sort(r+1,r+1+x,cmp2);
	for(int i=1;i<=x;++i)
		printf("%d ",r[i].id);
	printf("\n");
	for(int i=1;i<=y;++i)
		printf("%d ",c[i].id);
	return 0;
}
