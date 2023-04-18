#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int N=2e5+10;
char ch[N]; int T,k;
struct ll
{
	int x[N],w;
	ll(){memset(x,0,sizeof(x)),x[0]=1,w=0;}
}s;//,m,lft,tmp,pl,yi,shi,z,zc;
/*void init(ll a){memset(a.x,0,sizeof(a.x)),a.x[0]=1,a.w=0;}
bool cmp(ll a,ll b)//a>b?1:0
{
	if(a.w>b.w)return 1;
	if(a.w<b.w)return 0;
	for(int i=a.w;i>=1;i--)
		if(a.x[i]<b.x[i])return 0;
		else if(a.x[i]>b.x[i])return 1;
	return 1;
}*/
ll mnus(ll a,ll b)
{
	ll c; c.w=max(a.w,b.w);
	for(int i=1;i<=c.w;i++)
	{
		c.x[i]+=a.x[i]-b.x[i];
		if(c.x[i]<0)c.x[i+1]--,c.x[i]+=10;
	}
	while(!c.x[c.w])c.w--;
	return c;
}
/*ll pls(ll a,ll b)
{
	ll c; c.w=max(a.w,b.w);
	for(int i=1;i<=c.w;i++)
	{
		c.x[i]+=a.x[i]+b.x[i];
		c.x[i+1]+=c.x[i]/10;
		c.x[i]%=10;
	}
	if(c.x[c.w+1])c.w++;
	return c;
}
ll mul(ll a,ll b)
{
	ll c; c.w=a.w+b.w-1;
	for(int i=1;i<=a.w;i++)
		for(int j=1;j<=b.w;j++)
		{
			c.x[i+j-1]+=a.x[i]*b.x[j];
			c.x[i+j]+=c.x[i+j-1]/10;
			c.x[i+j-1]%=10;
		}
	if(c.x[c.w+1]) c.w++;
	while(!c.x[c.w])c.w--;
	return c;
}*/
void print_z(ll a)
{
    if(!a.w)printf("0");
	for(int i=a.w;i>0;i--)
		printf("%d",a.x[i]);
}
void print_r(ll a)
{
    if(!a.w)printf("0");
	for(int i=1;i<=a.w;i++)
		printf("%d",a.x[i]);
}
int main()
{
    //shi.w=2,shi.x[2]=1,yi.w=1,yi.x[1]=1;
    scanf("%d",&T);
    while(T--)
    {
        //init(s),init(m),init(tmp);
        scanf("%s",ch+1),s.w=strlen(ch+1);
        reverse(ch+1,ch+1+s.w);
        for(int i=1;i<=s.w;i++)
            s.x[i]=ch[i]-48;
        s=mnus(s,s),print_z(s);
        /*if(cmp(shi,s))
        {
            s=mnus(s,yi),print_z(s);
            printf("\n");
            continue;
        }*/
        /*m.w=s.w,m.x[m.w]=1;
        for(int i=1;i<m.w-1;i++)m.x[i]=9;
        if(!cmp(s,m))--m.w,m.x[m.w]=1,m.x[m.w-1]=0;
        lft=mnus(s,m),k=m.w-1,tmp.w=k;
        tmp.x[k]=9;
        if(cmp(tmp,lft))
        {
            lft.w=tmp.w,pl.w=tmp.w-1;
            for(int i=1;i<=pl.w;i++)
                pl.x[i]=9;
            lft=pls(lft,pl);
            print_z(lft),print_r(lft);
            printf("\n");
        }
        else
        {
            lft=mnus(lft,tmp),lft=mnus(lft,yi);
            z.w=max(0,lft.w-1);
            for(int i=2;i<=lft.w;i++)
                z.x[i-1]=lft.x[i];
            z=pls(z,yi),zc=mul(mnus(z,yi),shi);
            z.w=tmp.w,pl.w=tmp.w-1;
            for(int i=1;i<=pl.w;i++)
                pl.x[i]=9;
            z=pls(z,pl),print_z(z);
            lft=pls(lft,yi);
            tmp=mnus(lft,zc);
            tmp=mnus(tmp,yi);
            print_z(tmp),print_r(z);
            printf("\n");
        }*/
    }
	return 0;
}
