#include<bits/stdc++.h>
using namespace std;
struct point
{
    long long x,y;
}p[505];
bool judge(int i,int j,int k)
{
    long long a,b,c;
    a=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
    b=(p[j].x-p[k].x)*(p[j].x-p[k].x)+(p[j].y-p[k].y)*(p[j].y-p[k].y);
    c=(p[i].x-p[k].x)*(p[i].x-p[k].x)+(p[i].y-p[k].y)*(p[i].y-p[k].y);
    if(a*a+b*b+c*c-2*a*b-2*a*c-2*b*c==0)return false;
    if(b+c<a||a+b<c||a+c<b)return true;
    return false;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%lld%lld",&p[i].x,&p[i].y);
    int cnt=0;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            for(int k=j+1;k<=n;++k)
                if(judge(i,j,k))
                    ++cnt;
    printf("%d\n",cnt);
    return 0;
}
