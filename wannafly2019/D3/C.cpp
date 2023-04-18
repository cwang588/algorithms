#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const long long INF=1e18;
typedef long long ll;
ll w[20],h[20],q[20];
ll d[1<<15][20];
ll ans[1<<15];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)scanf("%lld%lld%lld",&w[i],&h[i],&q[i]);
    for(int i=0;i<(1<<n);i++)
    {
        ll cnt=0,area=0,H=0,W=0;
        for(int j=0;j<n;j++)
        {
            if((1<<j)&i)
            {
                W=max(W,w[j]);
                H=max(H,h[j]);
                cnt+=q[j];
                area+=w[j]*h[j]*q[j];
            }
        }
        ans[i]=cnt*W*H-area;
    }
    for(int i=0;i<(1<<n);i++)
    for(int j=0;j<=m;j++)d[i][j]=INF;
    d[0][0]=0;
    for(int i=0;i<(1<<n);i++)
    {
        int S=((1<<n)-1)^i;
        for(int j=S;j;j=(j-1)&S)
        for(int k=0;k<m;k++)d[i^j][k+1]=min(d[i^j][k+1],d[i][k]+ans[j]);
    }
    cout<<*min_element(d[(1<<n)-1],d[(1<<n)-1]+m+1)<<endl;
    return 0;
}


