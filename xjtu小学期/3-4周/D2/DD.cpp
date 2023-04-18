#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include<algorithm>
#define Ll long long 
using namespace std;
struct you{double x,y;}a[5000005];
int n,now,mi;
double c,v,m,x,ans;
bool cmp(you a,you b){return a.x<b.x;}
int main()
{
    scanf("%lf%lf%lf%lf%d",&v,&c,&m,&a[0].y,&n);
    for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    a[n+1].x=v;a[n+1].y=1e8;
    while(1){
        v=1e9;
        for(int i=now+1;i<=n+1;i++)
            if(a[i].x<=a[now].x+c*m)
                if(a[i].y<=v){
                    mi=i;
                    v=a[i].y;
                }else;else break;
        if(v==1e9){printf("No Solution");return 0;}
        if(v<=a[now].y){
            double need=(a[mi].x-a[now].x)/m;
            if(x>need)x-=need,need=0;else need-=x,x=0;
            ans+=need*a[now].y;
            now=mi;
        }else
            if(a[n+1].x<=a[now].x+c*m){
                double need=(a[n+1].x-a[now].x)/m;
                if(x>need)x-=need,need=0;else need-=x,x=0;  
                ans+=need*a[now].y;
                break;
            }else{
                ans+=(c-x)*a[now].y;
                x=c-((a[mi].x-a[now].x)/m);
                now=mi;
            }
    }
    printf("%.2lf",ans);
}

