#include<bits/stdc++.h>
#define int long long
#define maxn 9223372036854775807
using namespace std;
struct bale
{
	int pos,value,tot,sub;
	bool operator < (const bale&a)const
	{
		return pos<a.pos;
	} 
}b[100005];
signed main()
{
	int n,p;
	scanf("%lld%lld",&n,&p);
	for(int i=1;i<=n;++i)scanf("%d%d",&b[i].value,&b[i].pos),b[i].tot=b[i].pos+b[i].value,b[i].sub=b[i].pos-b[i].value;
	sort(b+1,b+1+n);
	int L=maxn,R=maxn;
	for(int i=1;i<=n;++i)
	{
		if(b[i].pos<p&&p<b[i+1].pos)
		{
			L=i;
			R=i+1;
			break;
		}
	}
	if(L==maxn)return !printf("-1\n");
	bool ky1=true,ky2=true;
	for(int i=1;i<=L;++i)
	{
		if(b[R].pos-b[i].pos<=b[i].value)
		{
			ky1=false;
			break;
		}
	} 	
	for(int i=R;i<=n;++i)
	{
		if(b[i].pos-b[L].pos<=b[i].value)
		{
			ky2=false;
			break;
		}
	} 	
	if(ky1&&ky2)return !printf("-1\n");
	int l=L,r=R,Maxl,Maxr,LL=L,RR=R;
	Maxl=0;
	Maxr=maxn;
	for(int i=1;i<=n;++i)
	{
		if(i<=L)Maxl=max(Maxl,b[i].tot);
		else Maxr=min(Maxr,b[i].sub);
	}
	while(LL>0&&b[LL].pos>=Maxr)--LL;
	while(RR<=n&&b[RR].pos<=Maxl)++RR;
	int ansl=maxn,ansr=maxn;
	while(l>LL)
	{
		while(r<=n&&b[r].pos-b[l].pos>b[r].value)++r;
		if(r==n+1)break;
		while(l>LL&&b[r].pos-b[l].pos>b[l].value)
		{
			ansl=min(ansl,b[r].pos-b[l].pos-b[l].value);
			--l; 
		}
	}
	l=L,r=R;
	while(r<RR)
	{
		while(l>0&&b[r].pos-b[l].pos>b[l].value)--l;
		if(l==0)break;
		while(r<RR&&b[r].pos-b[l].pos>b[r].value)
		{
			ansr=min(ansl,b[r].pos-b[l].pos-b[r].value);
			++r; 
		}
	}
	if(ansl==maxn&&ansr==maxn)printf("0\n");
	else printf("%lld\n",min(ansl,ansr));
	return 0;
} 
