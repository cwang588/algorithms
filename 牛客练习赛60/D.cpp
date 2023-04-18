#include<bits/stdc++.h>
using namespace std;
typedef long long __int128;
inline __int128 read(){
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void print(__int128 x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}
long long gcd(long long x,long long y)
{
	return y?gcd(y,x%y):x;
}
void exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return;
    }
    long long x1,y1;
    exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
}	
long long Floor(long long x,long long y)
{
	if(x*y>=0)
	{
		x=x>=0?x:-x;
		y=y>=0?y:-y;
		return x/y;
	}
	else
	{
		x=x>=0?x:-x;
		y=y>=0?y:-y;
		if(x%y==0)return -x/y;
		else return -(x/y+1);
	}
}
bool judge(long long x,long long y,long long B,long long C,long long K)
{
	long long tmp=Floor(K*y,B);
	return C*tmp+K*x>=0;
}
int ans[3];
int main()
{
	long long a,b,c,k;
//	scanf("%lld%lld%lld%lld",&a,&b,&c,&k);	a=read()''
	a=read();
	b=read();
	c=read();
	k=read();
	ans[0]=0,ans[1]=1,ans[2]=2;
	bool sw=false;
//	if(a<b)swap(a,b),sw=true;
//	if(a>c)swap(a,c),swap(ans[0],ans[2]);
	long long gcdd=gcd(b,c);
	for(long long i=0;i<=b;++i)
	{
		long long kk=k-a*i;
		if(kk%gcdd)continue;
		long long B=b/gcdd,C=c/gcdd,K=kk/gcdd;
		long long x,y;
		exgcd(B,C,x,y);
		if(judge(x,y,B,C,K)&&(x*K+C*Floor(K*y,B))>=0&&(y*K-B*Floor(K*y,B))>=0)
		{
//			if(!sw)return !printf("%lld %lld %lld\n",i,(x*K+C*Floor(K*y,B)),(y*K-B*Floor(K*y,B)));
//			else return !printf("%lld %lld %lld\n",(x*K+C*Floor(K*y,B)),i,(y*K-B*Floor(K*y,B)));
			print(i);
			printf(" ");
			print(x*K+C*Floor(K*y,B));
			printf(" ");
			print((y*K-B*Floor(K*y,B)));
			printf(" ");
			return 0;
		}
	}
	return 0;
}




