#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=5000005+10;
double D1,D2,C,P,ans,need;
int cnt,Ans[maxn],N;
bool bo=0,f=0;
struct hh
{
    double di,pi;
}e[maxn];

bool cmp(hh x,hh y)
{
    return x.di<y.di;
}
void done()
{
    e[0].pi=P;
    e[0].di=0;
    e[N+1].di=D1;
    int now=0,last;
    double have=0;
    while(now<=N)
    {
        bool flg=0,bo=0;
        for(int i=now+1;i<=N;++i)
        {
            if(e[i].pi<e[now].pi)
            {
              bo=1;
              if(e[i].di-e[now].di<=need) 
              { 
                ans+=(e[i].di-e[now].di)/D2*e[now].pi;
                have=0;
                now=i;
                last=i;
              }
              else flg=1;
              break;
          } 
        }  
        if(flg||!bo)
        {
            if(D1-e[now].di<=need) break;
            ans+=(C-have)*e[now].pi;
            int i=now+1;
            for(i=now+1;i<=N+1;++i)
              if(e[i].di-e[now].di>need) break;
            i--;
            have=C-(e[i].di-e[now].di)/D2;
            now=i;
            last=i;
        }
    }
    ans+=((D1-e[last].di)/D2-have)*e[last].pi;
}
int main()
{
    scanf("%lf%lf%lf%lf%d",&D1,&C,&D2,&P,&N);
    need=D2*C;
    for(int i=1;i<=N;++i) scanf("%lf%lf",&e[i].di,&e[i].pi);
    sort(e+1,e+N+1,cmp);
    e[0].di=0;
    for(int i=1;i<=N;++i)
      if(e[i].di-e[i-1].di>need) f=1;
    if(D1-e[N].di>D2*C) f=1;    
    ans=0.00;
    if(f) 
    {
        printf("No Solution");
        return 0;
    }
    done();
    printf("%.2lf",ans);
    return 0;
}

