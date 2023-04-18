#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
typedef long long ll;
const ll P=998244353;
ll mp[maxn+5],num,dp[maxn+5],mo2[maxn+5];
ll n,m,dx;
ll ttt[maxn+5]; 
inline char nc()
{
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline ll read()
{
	ll dx=0,num=1;
	char c=nc();
	for(;!(c<='9'&&c>='0');c=nc())if(c=='-')num=-1;
	for(;c<='9'&&c>='0';c=nc())dx=dx*10+c-'0';
	return dx*num;
}
char buf2[200] ;
inline void wr(ll dx) 
{
	if(dx==0)putchar('0');
    ll tmp=dx>0?dx:-dx;
    if(dx<0)putchar('-');
    ll cnt=0;
    while(tmp>0){
        buf2[cnt++]=tmp%10+'0';
        tmp/=10;
    }
    while(cnt>0)putchar(buf2[--cnt]);
    putchar('\n');
}
void pre()
{
	ll too=1,pusht=1;
	for(ll i=0;i<=18;i++){
		for(ll j=too;j<pusht;j++){
			mo2[j]=i-1;
		}
		too=pusht;
		pusht=pusht<<1;
	}
	ttt[0]=1ll;
	for(ll i=1;i<=17;i++)
	ttt[i]=ttt[i-1]*2ll;
	dp[0]=1ll;
	for(ll i=1;i<ttt[17];i++){
		for(ll s1=i;;)
		{
			if(!(s1>=ttt[mo2[i]])) break;
			dp[i]=(dp[i]+mp[s1]*dp[i^s1]%P)%P;
			s1=(s1-1)&i;
		}
	}
}
int main()
{
    n=read();
    for(ll i=1;i<=n;i++)
	{
    	dx=read();num=read();
    	mp[num]+=dx;
	}
	pre();
	m=read();
	while(m--){
		dx=read();
		wr(dp[dx]);
	}
    return 0;
}

