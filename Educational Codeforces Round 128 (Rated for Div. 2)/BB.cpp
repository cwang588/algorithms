#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    return s*w;
}
const int MAXN=1e3+5;
ll a[MAXN][MAXN],n,m,k,d,dp[MAXN][MAXN];
ll ma[MAXN];
struct node{
    ll id,v;
}dd[MAXN*2];
int fr,en;
int main(){
    n=read(),m=read(),k=read(),d=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            a[i][j]=read();
    for(int i=1;i<=n;++i){
    	for(int j=1;j<=m;++j)dp[i][j]=LLONG_MIN;
	}
    
    dp[n][m]=a[n][m];
    fr=1;
    for(int i=n;i>=1;--i){
        ma[i]=LLONG_MIN;
        while(fr<=en&&dd[fr].id>i+d)fr++;
        while(fr<=en&&dd[en].v<=ma[i+1])en--;
        if(i<n){
			dd[++en].id=i+1;
	        dd[en].v=ma[i+1];
	    }
        for(int j=m;j>=1;--j){
            if(i==n&&j==m)continue;
            if(j+k<=m){
                ma[i]=max(ma[i],dp[i][j+k]);
            }
            if(i<n){
				dp[i][j]=max(dd[fr].v,ma[i])+a[i][j];
			}
        	else dp[i][j]=ma[i]+a[i][j];
		}
        for(int j=1;j<=m;++j){
            ma[i]=max(ma[i],dp[i][j]);
        }
    }
    printf("%lld",dp[1][1]);
    //while(1);
    return 0;
}