#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct mt{
    ll a[3][3];
};
mt t(mt a,mt b,ll mod){
    mt res;
    int i,j,k;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            res.a[i][j]=0;
            for(k=0;k<3;k++){
                res.a[i][j]+=a.a[i][k]*b.a[k][j]%mod;
                res.a[i][j]%=mod;
            }
        }
    }
    return res;
}
mt power(mt a,ll b,ll mod){
    mt res;
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            res.a[i][j]=0;
        }
    }
    res.a[0][0]=res.a[1][1]=res.a[2][2]=1;
 
    while(b){
        if(b&1)res=t(res,a,mod);
        b>>=1;
        a=t(a,a,mod);
    }
    return res;
}
ll feb(ll n,ll mod){
    mt temp;
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            temp.a[i][j]=0;
        }
    }
    temp.a[0][1]=temp.a[1][1]=temp.a[1][0]=temp.a[1][2]=1;
    mt res=power(temp,n-1,mod);
    return (res.a[0][0]+res.a[0][1])%mod;
}
ll feb2(ll n,ll mod){
    mt temp;
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            temp.a[i][j]=0;
        }
    }
    temp.a[0][1]=temp.a[1][1]=temp.a[1][0]=temp.a[1][2]=temp.a[2][2]=1;
    mt res=power(temp,n-1,mod);
    return (res.a[0][0]+2*res.a[0][1]+res.a[0][2])%mod;
}
ll power(ll a,ll b,ll mod){
    ll res=1;
 
    while(b){
        if(b&1)res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
int main(){
    int m=1e9+7;
 
    int i,j;
    ll n,x,y,a,b;
    cin>>n>>x>>y>>a>>b;
    if(n==1){cout<<x%m;return 0;}
    if(n==2){cout<<y%m;return 0;}
    if(x%m==0||y%m==0||a%m==0){cout<<0;return 0;}
    x%=m;
    y%=m;
 
    a=power(a%m,b,m);       //这里要注意a对m取模
     
    cout<<power(x,feb(n-2,m-1),m)*power(y,feb(n-1,m-1),m)%m*power(a%m,feb2(n-2,m-1)%(m-1),m)%m<<endl;
 
}
